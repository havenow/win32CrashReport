#pragma once
#include <string>
using std::wstring;

namespace PublicLib{

	std::wstring GetIEProxy(const std::wstring& strUrl, std::wstring& strProxyBypass);
}