// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�: 
#include <windows.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

// C ����ʱͷ�ļ�
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


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
