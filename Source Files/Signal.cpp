/*
	Author: Isaiah Curtis
	Date: 12/23/2016

	Description:
	A very primitive class used to hold the signal 
	data type for signals passing through neurons
*/

#include "Signal.h"

/*
	This is a function which takes the weight and signal strength
	of the respective neuron and multiplies them to recieve a 
	weighted signal
*/
double Signal::getWeightedSignal() {
	return signalStrength * signalWeight;
}

/*
	The following functions are to update the strength and weight of each neuron
*/
void Signal::updateStrength(double strength) { signalStrength = strength; }
void Signal::updateWeight(double weight) { signalWeight = weight;  }

// A function to find the parent neuron so that the neurons 
// can interact as nodes to communicate with the whole network
INeuron * Signal::getParentNeuron() {
	return sender;
}