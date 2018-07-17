#include "StringPooler.h"

std::set<CStringPooler::PooledString> CStringPooler::m_pooledStrings;

CStringPooler::PooledString::PooledString(const char* str, int refCount /*=0*/)
	: m_string(str)
	, m_refCount(refCount)
{

}

const std::string* CStringPooler::GetString(const char * str)
{
	auto setInsertedResult = m_pooledStrings.insert(PooledString(str));
	auto it = setInsertedResult.first;
	auto existing = !(setInsertedResult.second);
	if(existing)
	{
		const_cast<PooledString*>(&(*it))->m_refCount++;
	}
	return &((*it).m_string);
}

CStringPooler::PooledString* CStringPooler::FindPooledString(const char *str)
{
	auto setFindResult = m_pooledStrings.find(PooledString{str});
	if(setFindResult != m_pooledStrings.end())
	{
		// found
	}
	return nullptr;
}

int CStringPooler::GetPoolCount()
{
	int count = 0;
	count = m_pooledStrings.size();
	return count;
}

bool operator<(const CStringPooler::PooledString& lhs, const CStringPooler::PooledString& rhs)
{
	return lhs.m_string < rhs.m_string;
}

bool operator==(const CStringPooler::PooledString& lhs, const CStringPooler::PooledString& rhs)
{
	return lhs.m_string == rhs.m_string;
}