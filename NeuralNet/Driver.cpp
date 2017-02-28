#include "Net.h"
#include <vector>
#include <iostream>
#include <math.h> 

using namespace std;

int main() {

	//e. g. {3, 2, 1} 3 input layers, 2 hidden neuons, 1 output neuron.
	vector<unsigned> topology;
	topology.push_back(1);
	topology.push_back(2);
	topology.push_back(1);
	Net net(topology);


	// teach the neural net NOT operations
	for (unsigned i = 0; i < 1000; ++i) {

		cout << "\n";
		cout << "Pass: " << i << "\n";
		cout << "----------------\n";

		vector<double> input, target, result;

		bool randomInput = (bool)(rand() % 2);
		input.push_back(static_cast<double>(randomInput));
		target.push_back(static_cast<double>(!randomInput));
		cout << "Input: " << input.back() << '\n';
		cout << "Target: " << target.back() << '\n';

		net.feedForward(input);
		net.getResults(result);

		cout << "Result: " << (bool)round(result.back()) << '\n';
		
		net.backProp(target);

	}

	system("PAUSE");
}