#pragma once

#include <list>

using namespace std;

namespace TemplateList
{
	template<class T>
	T Get(list<T> _list, size_t _index)
	{
		typename list<T>::iterator _it = _list.begin();
		size_t count = 0;

		while (_it != _list.end())
		{
			if (count == _index)
			{
				return *_it;
			}

			++_it;
			++count;
		}
	}
}
