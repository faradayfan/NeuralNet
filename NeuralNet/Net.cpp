#include "Net.h"

#include <iostream>

Net::Net(const vector<unsigned>& topology)
{
	unsigned numLayers = topology.size();
	for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum) {
		m_layers.push_back(Layer());
		unsigned numOutputs = (layerNum == topology.size() - 1) ? 0 : topology[layerNum + 1];

		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum) {
			m_layers.back().push_back(Neuron(numOutputs));
			cout << "Made a neuron!\n";
		}
	}
}

void Net::feedForward(const vector<double>& inputVals)
{
}

void Net::backProp(const vector<double>& targetVals)
{
}

void Net::getResults(vector<double>& resultVals) const
{
}
