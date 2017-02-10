/*
Author: Isaiah Curtis
Date: 1/10/2017
*/

#include "Prog.h"


int main() {
	NeuralNet ann({ 2, 1 }, 0.5, COST_STANDARD);

	vector<vector<double>> inputData = {
		{ 1,0 },
		{ 0,1 }
	};

	vector<vector<double>> outputData = {
		{ 1},
		{ 1},
	};

	for (int i = 0; i < 1000; i++) {
		int random = (rand() / double(RAND_MAX)) * inputData.size();
		ann.trainNetwork(inputData[random], outputData[random]);
		cout << ann.getTotalCost(outputData[random], ann.getOutput(inputData[random])) << endl;
	}

	cout << ann.getOutput(inputData[0])[0];

	cin.get();

	return 0;
}