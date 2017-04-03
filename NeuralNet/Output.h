#pragma once

#include "Interface.h"

template <class T>
class Output : Interface<T>
{
public:

	Output(vector<T> possibleValues) : Interface<T>(possibleValues)
	{

	}

	~Output()
	{
	}
};

