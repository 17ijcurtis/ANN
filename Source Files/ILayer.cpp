/*
Author: Isaiah Curtis
Date: 1/10/2017
*/

#include "ILayer.h"

// PUBLIC FUNCTIONS
// Retrieve array of neurons from layer
vector<INeuron*> ILayer::getNeurons() { return neurons; }

// Retrieve a specific neuron
INeuron* ILayer::getNeuron(int index) {
	return neurons[index];
}

unsigned short ILayer::getNumOfNeurons() { return neurons.size(); }