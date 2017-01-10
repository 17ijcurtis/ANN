/*
	Author: Isaiah Curtis
	Date: 12/23/2016
*/

#include "Neuron.h"

// CONSTRUCTOR
Neuron::Neuron(Signal inputSignals[], int inputSignalsLength) { 
	signals = inputSignals;
	signalsLength = inputSignalsLength;
}

// PRIVATE FUNCTIONS

// Provides a summation of all the weighted signals entering the neuron
double Neuron::contents() {
	double sum = 0;

	for (int i = 0; i < signalsLength; i++) {
		sum += signals[i].getWeightedSignal();
	}

	return sum;
}

void Neuron::updateSignalStrengths() {
	for (int i = 0; i < signalsLength; i++) {
		INeuron * temp = signals[i].getParentNeuron();
		signals[i].updateStrength(temp->activate());
	}
}

// PUBLIC FUNCTIONS
// Updates the signal strengh of all previous neurons and then returns the sigmoid of the contents of the current neuron
double Neuron::activate() {
	updateSignalStrengths();
	return sigmoid(contents()); 
}