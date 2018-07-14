#include "String.h"
#include "StringPooler.h"
#include <iostream>
#include <cassert>

#define _USE_ASSERT
#ifdef _USE_ASSERT
#define MASSERT(x,y) assert(x && y)
#else
#define MASSERT
#endif // _USE_ASSERT

void Test1()
{
	CString s1{"Hello"};
	CString s2{"World"};
	CString s3{"Hello"};
	CString s4{"Hello!"};
	CString s5{"World"};
	int pCount = CStringPooler::GetPoolCount();
	MASSERT(pCount == 3, "Wrong pool count");
}

int main()
{
	Test1();
}