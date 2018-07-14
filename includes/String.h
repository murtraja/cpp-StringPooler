#pragma once

#include <string>
#include <iostream>

class CString
{
	std::string *m_string{nullptr};
public:
	CString(const char *str);
};