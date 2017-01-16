/*
	Author: Isaiah Curtis
	Date: 1/11/2017
	Description: A neuron responsible for the output of the network
*/

#include "Receptron.h"

// CONSTRUCTOR
// We take a group of signals that point back to parent neurons and 
// initialize the receptron with them
Receptron::Receptron(vector<Signal*> signals, double* biasPointer) {
	this->signals = signals;
	this->biasPointer = biasPointer;
}


// PRIVATE FUNCTIONS
// PUBLIC FUNCTIONS
double Receptron::activate() {
	return sigmoid(contents());
}

double Receptron::contents() {
	double sum = 0;

	for (int i = 0; i < signals.size(); i++) {
		sum += signals[i]->getWeightedSignal();
	}

	return sum + *biasPointer;
}

// Using previous parents as nodes, we update the whole network
void Receptron::updateSignalStrength() {
	for (int i = 0; i < signals.size(); i++) {
		signals[i]->updateStrength(signals[i]->getParentNeuron()->activate());
	}
}