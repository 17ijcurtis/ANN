/*
	Author: Isaiah Curtis
	Date: 12/23/2016

	Description:
	A very primitive class used to hold the synapse 
	data type for signals passing through neurons
*/

#include "Synapse.h"



/*
	CONSTRUCTOR
	Parameters: INeuron* parentNeuron, double signalWeight
	Parameter Description: parentNeuron is a pointer to the neuron from which
		the signal is coming from.
	Description: Assigns parameter variable to respective class members.
*/
Synapse::Synapse(INeuron* parentNeuron, double weight) {
	this->parentNeuron = parentNeuron;
	this->weight = weight;
}



/*
Function Name: getSignalStrength
Type: double
Description: A function that returns the signal strength.
*/
double Synapse::getStrength() { return strength; }



/*
Function Name: getweight
Type: double
Description: A function that returns the signal weight.
*/
double Synapse::getWeight() { return weight; }



/*
	Function Name: getWeightedSignal
	Type: double
	Description: A function which returns the signal's strength multiplied by
		its weight.
*/
double Synapse::getWeightedSignal() { return strength * weight; }




/*
	Function Name: updateStrength
	Type: void
	Parameters: double strength
	Description: The strength is set to the parent neurons activation output
*/
void Synapse::updateStrength() { strength = parentNeuron->activate(); }



/*
	Function Name: updateWeight
	Type: void
	Parameters: double weight
	Description: Given a desired weight, the weight of the neuron is updated.
*/
void Synapse::setWeight(double weight) { this->weight = weight;  }



/*
	Function Name: getParentNeuron
	Type: INeuron*
	Description: A function to find the parent neuron so that the neurons can 
		interact as nodes to communicate with the whole network.
*/
INeuron* Synapse::getParentNeuron() { return parentNeuron; }