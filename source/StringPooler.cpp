#include "StringPooler.h"
CStringPooler::PooledString::PooledString(const char* str, int refCount /*=0*/, PooledString* next /*= nullptr*/)
	: m_string(str)
	, m_refCount(refCount)
	, m_next(next)
{

}

CStringPooler::PooledString* CStringPooler::head = nullptr;

std::string* CStringPooler::GetString(const char * str)
{
	PooledString* existing = FindPooledString(str);
	if(existing)
	{
		existing->m_refCount++;
		return &existing->m_string;
	}

	// create a new pooled string here
	PooledString* newPooledString = new PooledString(str);
	newPooledString->m_next = head;
	head = newPooledString;
	return &newPooledString->m_string;
}

CStringPooler::PooledString* CStringPooler::FindPooledString(const char *str)
{
	std::string requestedString(str);
	PooledString* pooledString = nullptr;
	ForEach([&requestedString, &pooledString](PooledString* current){
		if(current->m_string == requestedString)
		{
			pooledString = current;
			return true;
		}
		return false;
	});
	return pooledString;
}

int CStringPooler::GetPoolCount()
{
	int count = 0;
	ForEach([&count](PooledString* string){
		count++;
		return false;
	});
	return count;
}

void CStringPooler::ForEach(std::function<bool(CStringPooler::PooledString*)> f)
{
	PooledString* current = head;
	while(current)
	{
		bool done = f(current);
		if(done)
		{
			break;
		}
		current = current->m_next;
	}
}