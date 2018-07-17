#pragma once
#include <string>
#include <functional>
#include <iostream>
#include <set>
#include "tracer.h"

class CStringPooler
{
	class PooledString
	{
	public:
		std::string m_string;
		int m_refCount;
		PooledString(const char* str, int refCount = 0);

		
	};

	static std::set<PooledString> m_pooledStrings;

	static PooledString* FindPooledString(const char *str);

public:
	static const std::string* GetString(const char * str);

	// for testing purposes
	static int GetPoolCount();	

	friend bool operator<(const PooledString& lhs, const PooledString& rhs);
	friend bool operator==(const PooledString& lhs, const PooledString& rhs);
};

bool operator<(const CStringPooler::PooledString& lhs, const CStringPooler::PooledString& rhs);
bool operator==(const CStringPooler::PooledString& lhs, const CStringPooler::PooledString& rhs);