/*
	Author: Isaiah Curtis
	Date: 1/11/2017
	Description: The first layer, populated by perceptrons
*/

#include "InputLayer.h"

// Constructor
InputLayer::InputLayer(unsigned short numOfNeurons) {
	neurons.reserve(numOfNeurons);
	for (int i = 0; i < numOfNeurons; i++) 
		neurons.push_back(new Perceptron());
}
//PUBLIC

// Set inputs of each perceptron
void InputLayer::setInputs(vector<double> inputs) {
	// Minus one due to the presence of a Bias Neuron
	for (int i = 0; i < getNumOfNeurons(); i++)
		dynamic_cast<Perceptron *>(neurons[i])->setInput(inputs[i]); 
}
