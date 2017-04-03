#include "Net.h"

#include <iostream>
#include <cassert>

Net::Net(const vector<unsigned>& topology)
{
	unsigned numLayers = topology.size();
	for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum) {
		m_layers.push_back(Layer());
		unsigned numOutputs = (layerNum == topology.size() - 1) ? 0 : topology[layerNum + 1];

		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum) {
			m_layers.back().push_back(Neuron(numOutputs, neuronNum));
			cout << "Made a neuron!\n";
		}

		// force the bias nodes output value to 1.0
		m_layers.back().back().setOutputVal(1.0);
	}
}

void Net::feedForward(const vector<double>& inputVals)
{
	// make sure the input values match the number of input nodes in 
	// the neural net.
	assert(inputVals.size() == (m_layers[0].size() - 1));

	// for each input value,
	for (unsigned i = 0; i < inputVals.size(); ++i) {
		m_layers[0][i].setOutputVal(inputVals[i]);
	}

	// forward propagation

	for (unsigned layerNum = 1; layerNum < m_layers.size(); ++layerNum) {
		Layer &prevLayer = m_layers[layerNum - 1];
		for (unsigned n = 0; n < m_layers[layerNum].size() - 1; ++n) {
			m_layers[layerNum][n].feedForward(prevLayer);
		}
	}

}

void Net::backProp(const vector<double>& targetVals)
{
	// calc overall net error (RMS of outpur errors)
	Layer &outputLayer = m_layers.back();
	m_error = 0.0;

	for (unsigned n = 0; n < outputLayer.size() - 1; ++n) {
		double delta = targetVals[n] - outputLayer[n].getOutputVal();
		m_error += delta * delta;
	}

	m_error /= outputLayer.size() - 1;
	m_error = sqrt(m_error);

	// implement a recent averate measurement:

	m_recentAverageError = (m_recentAverageError * m_recentAverageSmoothingFactor + m_error)
		/ (m_recentAverageSmoothingFactor + 1.0);

	// calculate output layer gradients

	for (unsigned n = 0; n < outputLayer.size() - 1; ++n) {
		outputLayer[n].calcOutputGradients(targetVals[n]);
	}

	// calculate gradients on hidden layes

	for (unsigned layerNum = m_layers.size() - 2; layerNum > 0; --layerNum) {
		Layer &hiddenLayer = m_layers[layerNum];
		Layer &nextLayer = m_layers[layerNum + 1];

		for (unsigned n = 0; n < hiddenLayer.size(); ++n) {
			hiddenLayer[n].calcHiddenGradients(nextLayer);
		}
	}

	// for all layers from outpur to first hidden layer
	// updated connection weights

	for (unsigned layerNum = m_layers.size() - 1; layerNum > 0; --layerNum) {
		Layer &layer = m_layers[layerNum];
		Layer &prevLayer = m_layers[layerNum - 1];

		for (unsigned n = 0; n < layer.size() - 1; ++n) {
			layer[n].updateInputWeights(prevLayer);
		}
	}


}

void Net::getResults(vector<double>& resultVals) const
{
	resultVals.clear();

	for (unsigned n = 0; n < m_layers.back().size() - 1; ++n) {
		resultVals.push_back(m_layers.back()[n].getOutputVal());
	}
}

std::ostream & operator<<(std::ostream & out, const Net & n)
{

	cout << "\n--Net--\n";
	cout << "Error: " << n.m_error << "\n";
	cout << "Average Error: " << n.m_recentAverageError << "\n";
	cout << "Average Smoothing Factor: " << n.m_recentAverageSmoothingFactor << "\n";
	cout << "\n--Neurons--\n";
	for (unsigned i = 0; i < n.m_layers.size(); ++i) {
		cout << "Layer: " << i << "\n";
		for (unsigned j = 0; j < n.m_layers[i].size(); ++j) {
			cout << n.m_layers[i][j] << "\n";
		}
	}
	cout << "--End Neurons--" << "\n";


	return out;
}
