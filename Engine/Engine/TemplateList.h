#pragma once

#include <list>

using namespace std;

namespace TemplateList
{
	template<class T>
	T& Get(list<T*> _list, size_t _index)
	{
		typename list<T*>::iterator ite = _list.begin();
		size_t count = 0;

		while (ite != _list.end())
		{
			if (count == _index)
			{
				return **ite;
			}

			++ite;
			++count;
		}
		throw;
	}
}
