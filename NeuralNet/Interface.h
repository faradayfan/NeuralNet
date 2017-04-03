#pragma once

#include <vector>

using namespace std;

template <class T>
class Interface
{
private:
	T possibleValues;

public:

	Interface(vector<T>& possibleValues)
	{
		this->possibleValues = possibleValues;
	}

	~Interface()
	{
	}
	const vector<T> getPossibleValues() const {
		return this->possibleValues;
	}
};

