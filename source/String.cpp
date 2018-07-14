#include "String.h"
#include "StringPooler.h"

CString::CString(const char *str)
{
	m_string = CStringPooler::GetString(str);
}