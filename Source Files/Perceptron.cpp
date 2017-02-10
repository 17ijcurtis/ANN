/*
	Author: Isaiah Curtis
	Date: 12/23/2016
	Description: The class which the input layer of neurons aka perceptrons use
*/

#include "Perceptron.h"



/*	
	CONSTRUCTOR
	Description: Set input signal to 0.0
*/
Perceptron::Perceptron() : INeuron(){ 
	inputSignal = 0.0; 
}



// PUBLIC FUNCTIONS

/*
	Function Name: activate
	Type: double
	Description: Returns the contents of the neuron passed through the 
		specified activation function.
*/
double Perceptron::activate() {
	return sigmoid(contents());
}



/*
	Function Name: contents
	Type: double
	Description: Returns the input signal as the contents of the perceptron.
*/
double Perceptron::contents() {
	return inputSignal;
}



/*
	Function Name: setInput
	Type: void
	Parameters: double input
	Parameter Description: An input desired for the network.
	Description: Sets the input for the network, configuring the network for
		forward propogation.
*/
void Perceptron::setInput(double input) { inputSignal = input; }



/*
	Function Name: updateSignalStrength
	Type: void
	Description: This is not for use in the perceptron class. It simply needs
		to be defined so that the class is not abstract.
*/
void Perceptron::updateSignalStrength() {}