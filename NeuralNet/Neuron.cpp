#include "Neuron.h"


// 0.0 = slow learner
// 0.2 = meaduim learner
// 1.0 = reckless learner
double Neuron::eta = 0.15;
// 0.0 no momentum
// 0.5 moderate momentum
double Neuron::alpha = 0.5;

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
	for (unsigned c = 0; c < numOutputs; ++c) {
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}

	m_myIndex = myIndex;
}


Neuron::~Neuron()
{
}

void Neuron::calcOutputGradients(double targetVal)
{
	double delta = targetVal - m_outputVal;
	m_gradient = delta * Neuron::transferFunctionDerivative(m_outputVal);
}

void Neuron::calcHiddenGradients(const vector<Neuron> &nextLayer)
{
	double dow = sumDOW(nextLayer);
	m_gradient = dow * Neuron::transferFunctionDerivative(m_outputVal);
}

void Neuron::feedForward(const vector<Neuron> & prevLayer)
{
	double sum = 0.0;

	for (unsigned n = 0; n < prevLayer.size(); ++n) {
		sum += prevLayer[n].getOutputVal() * prevLayer[n].m_outputWeights[m_myIndex].weight;
	}

	m_outputVal = Neuron::transferFunction(sum);
	
}

void Neuron::updateInputWeights(vector<Neuron> & prevLayer)
{

	for (unsigned n = 0; n < prevLayer.size(); ++n) {
		Neuron &neuron = prevLayer[n];
		double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;

		double newDeltaWeight =
			eta * neuron.getOutputVal()
			* m_gradient
			+ alpha
			* oldDeltaWeight;

		neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
		neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
	}
}

double Neuron::randomWeight(void)
{
	return rand() / double(RAND_MAX); // get random number between 0 and 1;
}

double Neuron::transferFunction(double x)
{
	//tanh - output range [-1.0..1.0]

	return tanh(x);
}

double Neuron::transferFunctionDerivative(double x)
{
	return 1.0 - x * x;
}

double Neuron::sumDOW(const vector<Neuron> & nextLayer) const
{
	double sum = 0.0;

	for (unsigned n = 0; n < nextLayer.size() - 1; ++n) {
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}

	return sum;
}

std::ostream & operator<<(std::ostream & out, const Neuron & n)
{
	cout << "Neuron Index: " << n.m_myIndex << "\n";
	cout << "Gradient: " << n.m_gradient << "\n";
	cout << "Gradient: " << n.m_outputVal << "\n";
	for (unsigned i = 0; i < n.m_outputWeights.size(); ++i) {
		cout << "Connection: " << i << "\n";
		cout << "Weight: " << n.m_outputWeights[i].weight << "\n";
		cout << "Delta Weight: " << n.m_outputWeights[i].deltaWeight << "\n";
	}
	
	
	return out;
}
