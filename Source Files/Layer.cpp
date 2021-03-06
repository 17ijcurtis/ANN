/*
	Author: Isaiah Curtis
	Date: 1/13/2017
	Description: A standard layer class used for both hidden layers and output
		layers.
*/

#include "Layer.h"



/*
	CONSTRUCTOR
	Parameters: unsigned short numOfNeurons, ILayer* previousLayer
	Parameter Description: The number of neurons to be created in the layer and
		a pointer to the previous layer.
	Description: The constructor initializes the bias pointer with a new 
		pointer from the heap and sets the value to a random value between 0.0
		and 1.0. Then create an array of synapses connected to the neurons of 
		the previous layer.  Each neuron in this layer is given this array of synapses
*/
Layer::Layer(unsigned short numOfNeurons, ILayer* previousLayer) {
	neurons.reserve(numOfNeurons);

	for (int i = 0; i < numOfNeurons; i++) {
		vector<Synapse*> tempSynapses;
		tempSynapses.reserve(previousLayer->getNumOfNeurons());

		for (int j = 0; j < previousLayer->getNumOfNeurons(); j++) {
			tempSynapses.push_back(new Synapse(previousLayer->getNeuron(j), (rand() / double(RAND_MAX)) - .5));

			// init axon synapses
			previousLayer->getNeuron(j)->getAxon()->childSynapses.push_back(tempSynapses[j]);
		}
		neurons.push_back(new Neuron(tempSynapses, (rand() / double(RAND_MAX)) - .5));
	}

	for (int i = 0; i < previousLayer->getNumOfNeurons(); i++) {
		for (int j = 0; j < numOfNeurons; j++) {
			previousLayer->getNeuron(i)->getAxon()->childNeurons.push_back(neurons[j]);
		}
	}
}



/*
	DESTRUCTOR
	Description: Delete bias pointer and the pointers to neurons in the neuron
		array as well as the the synapses.
*/
Layer::~Layer() {

	// Each neuron holds the pointers to the synapses coming from the previous
	// layer and I dont want to delete them multiple times in the destructor of
	// each neuron so Ill delete them once here
	for (Synapse* synapse : static_cast<Neuron*>(neurons[0])->getSynapses()) {
		delete synapse;
	}
	
	// Delete axons
	for (INeuron* neuron : neurons) {
		delete neuron->getAxon();
	}

	// Now delete neurons
	for (INeuron* neuron : neurons)
		delete neuron;

}