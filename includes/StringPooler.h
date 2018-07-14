#pragma once
#include <string>
#include <iostream>
#include "tracer.h"

class CStringPooler
{
	class PooledString
	{
	public:
		std::string m_string;
		int m_refCount;
		PooledString* m_next;
		PooledString(const char* str, int refCount = 0, PooledString* next = nullptr);
	};
	static PooledString* head;

	static PooledString* FindPooledString(const char *str);

public:
	static std::string* GetString(const char * str);	
};