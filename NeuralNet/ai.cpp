#include "ai.h"



AI::AI(vector<Input<input_t>> inputs, vector<Output<output_t>> outputs)
{
	vector<unsigned> topology;
	unsigned inputsNum = inputs.size();
	for (unsigned inputsNum = inputs.size(); inputsNum >= outputs.size(); --inputsNum) {
		topology.push_back(inputsNum);
	}

	this->net = new Net(topology);
	
}


AI::~AI()
{
}
