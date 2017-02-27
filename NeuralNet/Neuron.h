#pragma once
#include "Connection.h"
#include <vector>
#include <random>

using namespace std;

class Neuron
{
public:
	Neuron(unsigned numOutputs);
	~Neuron();
private:
	static double randomWeight(void);
	double m_outputVal;
	vector<Connection> m_outputWeights;
};

