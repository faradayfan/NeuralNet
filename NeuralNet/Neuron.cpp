#include "Neuron.h"



Neuron::Neuron(unsigned numOutputs)
{
	for (unsigned c = 0; c < numOutputs; ++c) {
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}
}


Neuron::~Neuron()
{
}

double Neuron::randomWeight(void)
{
	return rand() / double(RAND_MAX); // get random number between 0 and 1;
}
