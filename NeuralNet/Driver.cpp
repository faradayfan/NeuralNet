#include "Net.h"
#include "ai.h"
#include "Input.h"
#include "Output.h"
#include <vector>
#include <iostream>
#include <math.h> 
// 5 input parity

using namespace std;

void not();
void binNumbers();
void inputParityTest();

int main() {
	inputParityTest();

	system("PAUSE");
}


void binNumbers() {
	vector<unsigned> topology;
	topology.push_back(8);	// 8 bit inputs
	topology.push_back(12);
	topology.push_back(12);
	topology.push_back(1);
	Net net(topology);

}

void inputParityTest() {
	vector<Input<AI::input_t>> inputs;
	vector<AI::input_t> values = { 0, 1 };
	vector<Output<AI::output_t>> outputs;

	inputs.push_back(Input<AI::input_t>(values));
	inputs.push_back(Input<AI::input_t>(values));
	inputs.push_back(Input<AI::input_t>(values));
	inputs.push_back(Input<AI::input_t>(values));
	inputs.push_back(Input<AI::input_t>(values));
	inputs.push_back(Input<AI::input_t>(values));
	inputs.push_back(Input<AI::input_t>(values));
	inputs.push_back(Input<AI::input_t>(values));


	outputs.push_back(Output<AI::output_t>(values));

	AI ai(inputs, outputs);
}

// an example not operation neural net
void not() {
	//e. g. {3, 2, 1} 3 input layers, 2 hidden neuons, 1 output neuron.
	vector<unsigned> topology;
	topology.push_back(1);
	topology.push_back(2);
	topology.push_back(1);
	Net net(topology);


	// teach the neural net NOT operations
	for (unsigned i = 0; i < 200; ++i) {

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

	cout << net;

}