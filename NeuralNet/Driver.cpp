
#include <vector>
#include "Net.h"

using namespace std;

int main() {

	//e. g. {3, 2, 1} 3 input layers, 2 hidden neuons, 1 output neuron.
	vector<unsigned> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);
	Net myNet(topology);

	vector<double> inputVals;
	myNet.feedForward(inputVals);

	vector<double> targetVals;
	myNet.backProp(targetVals);

	vector<double> resultVals;
	myNet.getResults(resultVals);

	system("PAUSE");
}