/*
	Author: Isaiah Curtis
	Date: 12/23/2016

	Description: The class which the input layer of neurons aka perceptrons use
*/

#include "Perceptron.h"

Perceptron::Perceptron(double * biasPointer) { 
	this->biasPointer = biasPointer;
	inputSignal = 0.0; 
}

double Perceptron::activate() {
	return sigmoid(inputSignal + *biasPointer); 
}
void Perceptron::setInput(double input) { inputSignal = input; }