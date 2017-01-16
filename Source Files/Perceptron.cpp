/*
	Author: Isaiah Curtis
	Date: 12/23/2016

	Description: The class which the input layer of neurons aka perceptrons use
*/

#include "Perceptron.h"

Perceptron::Perceptron() { 
	inputSignal = 0.0; 
}

double Perceptron::activate() {
	return sigmoid(contents());
}

double Perceptron::contents() {
	return inputSignal;
}

void Perceptron::setInput(double input) { inputSignal = input; }

// NOT FOR USE
void Perceptron::updateSignalStrength() {}