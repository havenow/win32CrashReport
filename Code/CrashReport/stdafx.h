// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
// Windows 头文件: 
#include <windows.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <string>
#include <vector>
using namespace std;

#include <AppHelper.h>
#include <PublicLib/XYLog.h>
#include <PublicLib/StrHelper.h>
#include <PublicLib/Common.h>
#include <PublicLib/json/json-forwards.h>
#include <PublicLib/json/json.h>
#include <PublicLib/md5.h>
#include <PublicLib/HttpClient.h>
#include <PublicLib/Markup.h>
#include <PublicLib/System.h>
#include <PublicLib/FileHelper.h>
#include <atlfile.h>


// TODO:  在此处引用程序需要的其他头文件
