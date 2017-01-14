/*
	Author: Isaiah Curtis
	Date: 12/23/2016

	Description: The class which all basic neurons use
*/

#include "Neuron.h"

// CONSTRUCTOR
Neuron::Neuron(vector<Signal*> signals) { 
	this->signals = signals;
}

// PRIVATE FUNCTIONS

// Provides a summation of all the weighted signals entering the neuron
double Neuron::contents() {
	double sum = 0;

	for (int i = 0; i < signals.size(); i++) {
		sum += signals[i]->getWeightedSignal();
	}

	return sum;
}

void Neuron::updateSignalStrengths() {
	for (int i = 0; i < signals.size(); i++) {
		signals[i]->updateStrength(signals[i]->getParentNeuron()->activate());
	}
}

// PUBLIC FUNCTIONS
// Updates the signal strengh of all previous neurons and then returns the sigmoid of the contents of the current neuron
double Neuron::activate() {
	updateSignalStrengths();
	return sigmoid(contents()); 
}