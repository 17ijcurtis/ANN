/*
	Author: Isaiah Curtis
	Date: 1/11/2017
	Description: The first layer, populated by perceptrons
*/

#include "InputLayer.h"

// Constructor
InputLayer::InputLayer(unsigned short numOfNeurons) {
	// Set bias with a random value
	bias = new double(rand() / double(RAND_MAX));

	neurons.reserve(numOfNeurons);
	for (int i = 0; i < numOfNeurons; i++) 
		neurons.push_back(new Perceptron(bias));
}
//PUBLIC

// Set inputs of each perceptron
void InputLayer::setInputs(vector<double> inputs) {
	// Minus one due to the presence of a Bias Neuron
	for (int i = 0; i < getNumOfNeurons(); i++)
		dynamic_cast<Perceptron *>(neurons[i])->setInput(inputs[i]); 
}

double InputLayer::getBias() { return *bias; }
void InputLayer::setBias(double bias) { *this->bias = bias; }