#pragma once

#include "Input.h"
#include "Output.h"
#include "Net.h"
#include <vector>


using namespace std;





class AI
{
private:
	Net* net;


public:
	typedef int input_t;
	typedef int output_t;

	// this should be able to take number of inputs, the input types
	AI(vector<Input<input_t>> inputs, vector<Output<output_t>> outputs);
	~AI();
};

