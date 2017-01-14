/*
	Author: Isaiah Curtis
	Date: 1/11/2017
	Description: A neuron responsible for the output of the network
*/

#include "Receptron.h"

// CONSTRUCTOR
// We take a group of signals that point back to parent neurons and 
// initialize the receptron with them
Receptron::Receptron(vector<Signal*> signals) {
	this->signals = signals;
}


// PRIVATE FUNCTIONS
// Using previous parents as nodes, we update the whole network
void Receptron::updateSignalStrengths() {
	for (int i = 0; i < signals.size(); i++) {
		signals[i]->updateStrength(signals[i]->getParentNeuron()->activate());
	}
}

double Receptron::contents() {
	double sum = 0;

	for (int i = 0; i < signals.size(); i++) {
		sum += signals[i]->getWeightedSignal();
	}

	return sum;
}

// PUBLIC FUNCTIONS
// The activate function of the the Receptron simply returns 
// the equivalent of contents for other types of neurons
double Receptron::activate() {
	// We must first update the signal strengths so that we
	// have an up to date network.
	updateSignalStrengths();
	return sigmoid(contents());
}
