/*
	Author: Isaiah Curtis
	Date: 1/10/2017

	Description: A class used to initialize a basic neural network by specifying given dimensions
	A more custom neural network may still be created but it must be done so manually
*/

#include "NeuralNet.h"

// CONSTRUCTOR

// numOfNeuronsPerLayer.size() must be >= 2
NeuralNet::NeuralNet(vector<unsigned short> numOfNeuronsPerLayer) {
	layers.reserve(numOfNeuronsPerLayer.size());

	for (int i = 0; i < numOfNeuronsPerLayer.size(); i++) {
		if (i == 0) {
			// Input Layer
			layers.push_back(new InputLayer(numOfNeuronsPerLayer[i]));
		} else if (i == numOfNeuronsPerLayer.size() - 1) {
			// Output Layer
			layers.push_back(new OutputLayer(numOfNeuronsPerLayer[i], layers[i - 1]));
		} else {
			// Hidden Layer
			layers.push_back(new HiddenLayer(numOfNeuronsPerLayer[i], layers[i - 1]));
		}
	}
}

vector<double> NeuralNet::getOutput(vector<double> input) {
	static_cast<InputLayer*>(layers[0])->setInputs(input);
	return static_cast<OutputLayer*>(layers[layers.size() - 1])->getOutput();
}