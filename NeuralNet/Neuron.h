#pragma once
// Class: Neuron
// Short Description:
// Long Description: 
// Author: John Miller
// Date: 2/27/2017


#include "Connection.h"
#include <vector>
#include <random>
#include <cmath>
#include <iostream>

using namespace std;


class Neuron
{
	
public:
	Neuron(unsigned numOutputs, unsigned myIndex);
	~Neuron();
	void setOutputVal(double val) { m_outputVal = val; };
	double getOutputVal() const { return m_outputVal; };
	void calcOutputGradients(double targetVal);
	void calcHiddenGradients(const vector<Neuron> &nextLayer);
	void feedForward(const vector<Neuron> &prevLayer);
	void updateInputWeights(vector<Neuron> &prevLayer);
	friend std::ostream& operator<<(std::ostream& out, const Neuron& n);
private:
	
	static double eta;		// [0.0..1.0] overall net training rate
	static double alpha;		// [0.0..n] multiplier of last weight
	static double randomWeight(void);
	static double transferFunction(double x);
	static double transferFunctionDerivative(double x);
	double sumDOW(const vector<Neuron> &nextLayer) const;
	double m_outputVal;
	unsigned m_myIndex;
	double m_gradient;
	
	vector<Connection> m_outputWeights;
};


