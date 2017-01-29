/*
	Author: Isaiah Curtis
	Date: 1/11/2017
	Description: The first layer, populated by perceptrons
*/

#include "InputLayer.h"

/*
	CONSTRUCTOR
	Parameters: unsigned short numOfNeurons
	Parameter Description: The number of neurons desired in the network.
	Description: Create the specified number of neurons in the network.
*/
InputLayer::InputLayer(unsigned short numOfNeurons) {
	neurons.reserve(numOfNeurons);
	for (int i = 0; i < numOfNeurons; i++) 
		neurons.push_back(new Perceptron());
}


/*
	DESTRUCTOR
	Description: Delete perceptron pointers within layer.
*/
InputLayer::~InputLayer() {
	for (INeuron* neuron : neurons)
		delete neuron;
}



// PUBLIC FUNCTIONS


/*
	Function Name: setInputs
	Type: void
	Parameters: vector<double> inputs
	Parameter Description: An array of inputs to be fed into the network.
	Description: Sets the input of each perceptron to the specified value.
*/
void InputLayer::setInputs(vector<double> inputs) {
	// Minus one due to the presence of a Bias Neuron
	for (int i = 0; i < getNumOfNeurons(); i++)
		dynamic_cast<Perceptron *>(neurons[i])->setInput(inputs[i]); 
}
