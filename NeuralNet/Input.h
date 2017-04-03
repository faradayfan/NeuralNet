#pragma once
#include "Interface.h"


template <class T>
class Input : Interface<T>
{
	
	
private:

public:

	Input(vector<T> possibleValues) : Interface<T>(possibleValues)
	{
	}

	~Input()
	{
	}
};

