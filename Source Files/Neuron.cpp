/*
	Author: Isaiah Curtis
	Date: 12/23/2016

	Description: The class which all basic neurons use
*/

#include "Neuron.h"

// CONSTRUCTOR
Neuron::Neuron(vector<Signal*> signals, double * biasPointer) { 
	this->signals = signals;
	this->biasPointer = biasPointer;
}

// PRIVATE FUNCTIONS

// PUBLIC FUNCTIONS
double Neuron::activate() {
	return sigmoid(contents()); 
}

// Provides a summation of all the weighted signals entering the neuron
// as well as biases
double Neuron::contents() {
	double sum = 0;

	for (int i = 0; i < signals.size(); i++) {
		sum += signals[i]->getWeightedSignal();
	}

	return sum + *biasPointer;
}

void Neuron::updateSignalStrength() {
	for (int i = 0; i < signals.size(); i++) {
		signals[i]->updateStrength(signals[i]->getParentNeuron()->activate());
	}
}

vector<Signal*> Neuron::getSignals() { return signals; }