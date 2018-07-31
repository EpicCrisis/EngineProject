
#pragma once

#include "TemplateList.h"

using namespace std;

template <class T>
class ParticleObjectContainer
{
private:
	list<T*> m_list;

public:
	ParticleObjectContainer()
	{
	}

	~ParticleObjectContainer()
	{
		list<ParticleObject*>::iterator ite = m_list.begin();

		while (ite != m_list.end())
		{
			delete *ite;
			++ite;
		}
		m_list.clear();
	}

	list<T*>& GetList()
	{
		return m_list;
	}

	T& GetItem(unsigned int index)
	{
		return TemplateList::Get(GetList(), index);
	}
};