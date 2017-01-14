/*
	Author: Isaiah Curtis
	Date: 1/13/2017
	Description: The layer containing the receptrons
*/

#include "OutputLayer.h"

// CONSTRUCTOR

OutputLayer::OutputLayer(unsigned short numOfNeurons, ILayer * previousLayer) {
	neurons.reserve(numOfNeurons);

	for (int i = 0; i < numOfNeurons; i++) {
		// An array to hold all the signals coming from the previous layer of neurons
		// Initialize weight of all signals to 0.5
		vector<Signal*> tempSignals;
		tempSignals.reserve(previousLayer->getNumOfNeurons());

		// Assign signals with random weights spanning from -.5 to .5
		// Later there will be an enum of which an option is chosen by the user
		// at the time of the creation of the network with which he can choose how 
		// the weights should be initialized
		for (int j = 0; j < previousLayer->getNumOfNeurons(); j++)
			tempSignals.push_back(new Signal(previousLayer->getNeuron(j), (rand() / double(RAND_MAX)) - .5));

		neurons.push_back(new Receptron(tempSignals));
	}
}

// PUBLIC FUNCTIONS

vector<double> OutputLayer::getOutput() {
	vector<double> output;
	output.reserve(getNumOfNeurons());

	for (int i = 0; i < getNumOfNeurons(); i++) {
		output.push_back(neurons[i]->activate());
	}

	return output;
}