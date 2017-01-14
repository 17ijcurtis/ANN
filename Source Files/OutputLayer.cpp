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

		for (int j = 0; j < previousLayer->getNumOfNeurons(); j++)
			tempSignals.push_back(new Signal(previousLayer->getNeuron(j), 0.5));

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