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
  ////禁用SetUnhandledExceptionFilter,防止异常回调函数被覆盖.
	DisableSetUnhandledExceptionFilter();
```

直接打开Debug下的win32CrashReport.exe，点击关于的确定按钮，会生成errfile.dat和errfile.dmp文件，在%appdata%的win32CrashReport目录下可以看到该文件。
![](https://github.com/havenow/win32CrashReport/blob/master/1.png)
