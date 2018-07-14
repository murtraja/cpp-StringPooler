#pragma once
#include <string>
#include <functional>
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


	static void ForEach(std::function<bool(CStringPooler::PooledString*)> f);
	static PooledString* FindPooledString(const char *str);

public:
	static std::string* GetString(const char * str);

	// for testing purposes
	static int GetPoolCount();	
};