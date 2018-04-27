win32程序异常的处理

```c++
void DisableSetUnhandledExceptionFilter()
{
	void *addr = (void*)GetProcAddress(LoadLibrary(_T("kernel32.dll")), "SetUnhandledExceptionFilter");
	if (addr)
	{
		unsigned char code[16];
		int size = 0;
		code[size++] = 0x33;
		code[size++] = 0xC0;
		code[size++] = 0xC2;
		code[size++] = 0x04;
		code[size++] = 0x00;

		DWORD dwOldFlag, dwTempFlag;
		VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &dwOldFlag);
		WriteProcessMemory(GetCurrentProcess(), addr, code, size, NULL);
		VirtualProtect(addr, size, dwOldFlag, &dwTempFlag);
	}
}

  //指定异常处理的回调函数
	SetUnhandledExceptionFilter(CExceptionHandler::MyCrashHandler);
  //禁用SetUnhandledExceptionFilter,防止异常回调函数被覆盖.
	DisableSetUnhandledExceptionFilter();
  //生成dmp文件	
	::MiniDumpWriteDump(::GetCurrentProcess(), ::GetCurrentProcessId(), hFile, mdt, &einfo, NULL, NULL);
```

直接打开Debug下的win32CrashReport.exe，点击关于的确定按钮，会生成errfile.dat和errfile.dmp文件，在%appdata%的win32CrashReport目录下可以看到该文件。
![](https://github.com/havenow/win32CrashReport/blob/master/1.png)


```c++
============================================
摘录自msdn
/****************************** Module Header ******************************\
Module Name:  CppExceptionHandling.cpp
Project:      CppExceptionHandling
Copyright (c) Microsoft Corporation.

- to be finished.

This source is subject to the Microsoft Public License.
See http://www.microsoft.com/opensource/licenses.mspx#Ms-PL.
All other rights reserved.

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, 
EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
\***************************************************************************/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <strsafe.h>
#include <shlwapi.h>
#include <dbghelp.h>
#pragma comment(lib, "Dbghelp.lib")
#pragma comment(lib, "shlwapi.lib")


// This method is to write mini dump of current process to 
// CppExceptionHandling.dmp file. 
LONG WINAPI WriteMiniDump(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
 // EXCEPTION_CONTINUE_SEARCH means it continue to 
 // execute subsequent exception handlers.
 LONG rc = EXCEPTION_CONTINUE_SEARCH;

 HMODULE hDll = NULL;
 TCHAR szDumpFile[MAX_PATH];
 StringCchPrintf(szDumpFile, MAX_PATH, _T("CppExceptionHandling.dmp"));

 HANDLE hDumpFile;
 hDumpFile = CreateFile(szDumpFile, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, 
  CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

 if (hDumpFile != INVALID_HANDLE_VALUE)
 {
  MINIDUMP_EXCEPTION_INFORMATION ExInfo;

  ExInfo.ThreadId = GetCurrentThreadId();
  ExInfo.ExceptionPointers = ExceptionInfo;
  ExInfo.ClientPointers = TRUE;

  // Write the information into the dump
  if (MiniDumpWriteDump(
   GetCurrentProcess(), // Handle of process
   GetCurrentProcessId(), // Process Id
   hDumpFile,    // Handle of dump file
   MiniDumpNormal,   // Dump Level: Mini
   &ExInfo,    // Exception information
   NULL,     // User stream parameter
   NULL))     // Callback Parameter
  {
   rc = EXCEPTION_CONTINUE_SEARCH;
  }
  else
  {
   _tprintf(_T("MiniDumpWriteDump failed w/err 0x%08lx\n"), GetLastError());
  }

  CloseHandle(hDumpFile);
 }
 else
 {
  _tprintf(_T("CreateFile failed w/err 0x%08lx\n"), GetLastError());
 }

 return rc;
}


#pragma region Structured Exception

void ThrowStructuredException()
{
}

void ThrowAndHandleStructuredException()
{
}

#pragma endregion


#pragma region Vectored Exception

// The registered exception handler
LONG WINAPI VectoredExceptionHandler(struct _EXCEPTION_POINTERS *ExceptionInfo)
{    
 WriteMiniDump (ExceptionInfo);
 printf("This vectored handler is always called first\n");
 return EXCEPTION_CONTINUE_SEARCH;
}

void ThrowAndHandleVectoredException()
{
 // Registers a vectored exception handler
 PVOID handler = AddVectoredExceptionHandler(0, VectoredExceptionHandler);

 // Raise a fake exception for demo
 __try
 {
  printf("RaiseException: Raise an exception\n");
  RaiseException(1,0,0,NULL); 
 }  
 __except(EXCEPTION_EXECUTE_HANDLER)
 {
  printf("This is a exception handler\n");
 }

 // Remove the vectored exception handler
 RemoveVectoredExceptionHandler(handler);
}

#pragma endregion


int _tmain(int argc, _TCHAR* argv[])
{
 ThrowAndHandleVectoredException();

 return 0;
}
```
