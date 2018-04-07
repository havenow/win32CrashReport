#pragma once


/************************************************************************/
/* 定义一些全局变量                                                     */
/************************************************************************/
#define DECLARE_STR(x,y)	static const wchar_t* x = y;


DECLARE_STR(GUI_CLASS_NAME,		L"GuiFoundation")

DECLARE_STR(MUTEX_NAME, L"win32CrashReportMetux")

//主程序定义
#ifdef APP_MAIN
DECLARE_STR(MAIN_WND_NAME,		L"悟饭游戏厅")
DECLARE_STR(MUTEX_NAME,			L"5funGameHallMetux")
DECLARE_STR(NOTIFY_ICON_NAME,	L"悟饭游戏厅")
#endif

//更新程序定义
#ifdef APP_UPDATE
DECLARE_STR(UPDATE_WND_NAME,	L"悟饭游戏厅更新程序")
#define SCRIPT_FILE_NAME	L"UpdateScript.XML"	//配置文件名称
#endif

//卸载程序定义
#ifdef APP_UNINSTALL
DECLARE_STR(UNINSTALL_WND_NAME, L"悟饭游戏厅卸载程序")
#endif

//安装程序定义
#ifdef APP_SETUP
DECLARE_STR(SETUP_WND_NAME,		L"悟饭游戏厅安装程序")
#define SPACE_NEED			(200<<20)		//至少需要200M安装空间
#endif

//主程序名
#define EXE_MAIN			L"5funGameHall.exe"
#define EXE_RENDER			L"5funGameHallWeb.exe"
#define EXE_UNINSTALL		L"Uninstall.exe"
#define EXE_UPDATE			L"5funUpdate.exe"
#define EXE_BUGREPORT		L"5funBugReport.exe"
#define EXE_EMULATOR		L"5funEmulator.exe"
#define EXE_EMULATOR_PSP	L"PSPEmulator.exe"


#define SOFT_NAME			L"悟饭游戏厅"
#define SOFT_ROOT_DIR		L"5funGameHall"

//快捷方式名称
#define SHORTCUT_MAIN_NAME	L"悟饭游戏厅"

//注册表主键名
#define REG_ROOT_NAME		L"5funGameHall"

#define REG_COMPANY			L"嘉兴游辰网络科技有限公司"
#define REG_URL				L"http://www.5fun.cn/"


//PC官网链接
#define PC_URL				L"http://pc.5fun.com/"