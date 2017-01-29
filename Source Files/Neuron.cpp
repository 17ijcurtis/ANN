/*
	Author: Isaiah Curtis
	Date: 12/23/2016

	Description: The class which all basic neurons use
*/

#include "Neuron.h"

/* 
	CONSTRUCTOR
	Parameters: vector<Synapse*> synapses, double* biaspointer
	Parameter Description: The vector of synapses acting as input signals for
		the neuron and a pointer to the bias neuron for the layer in which the
		neuron is being held.
	Description: The parameters are stored in the class.
*/
Neuron::Neuron(vector<Synapse*> synapses, double* biasPointer) { 
	this->synapses = synapses;
	this->biasPointer = biasPointer;
}



// PUBLIC FUNCTIONS

/*
	Function Name: activate
	Type: double
	Description: Returns the contents of the neuron passed through the 
		specified activation function.
*/
double Neuron::activate() {
	return sigmoid(contents()); 
}



/*
	Function Name: contents
	Type: double
	Description: Combines the weights signals of each synapse as well as the 
		bias neuron and returns the value.
*/
double Neuron::contents() {
	double sum = 0;

	for (int i = 0; i < synapses.size(); i++) {
		sum += synapses[i]->getWeightedSignal();
	}

	return sum + *biasPointer;
}



/*
	Function Name: updateSignalStrength
	Type: void
	Description: Updates the signal strenth of each synapse by activated their
		parent neurons.
*/
void Neuron::updateSignalStrength() {
	for (int i = 0; i < synapses.size(); i++) {
		synapses[i]->updateStrength();
	}
}


/*
	Function Name: getSynapses
	Type: vector<Synapse*>
	Description: Returns the neurons incoming synapses.
*/
vector<Synapse*> Neuron::getSynapses() { return synapses; }