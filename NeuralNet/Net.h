#pragma once
// Class: Net
// Short Description: This is a artificial neural network.
// Long Description: 
// Author: John Miller
// Date: 2/27/2017
// This project was building following this tutorial.
// https://www.youtube.com/watch?v=KkwX7FkLfug
// this blog also covers this type of implementation 
// http://briandolhansky.com/blog/2014/10/30/artificial-neural-networks-matrix-form-part-5



#include "Neuron.h"
#include <vector>

using namespace std;

typedef vector<Neuron> Layer;

class Net {
	
public:
	Net(const vector<unsigned> &topology);
	void feedForward(const vector<double> &inputVals);
	void backProp(const vector<double> &targetVals);
	void getResults(vector<double> &resultVals) const;

	friend std::ostream& operator<<(std::ostream& out, const Net& n);

private:
	
	double m_error;
	double m_recentAverageError;
	double m_recentAverageSmoothingFactor;
	vector<Layer> m_layers;  // m_layer[layer_num][neuron_num];
};