/*
	Author: Isaiah Curtis
	Date: 1/10/2017
	Description: An abstract layer class from which all other layer classes are
		derived.  It contains a vector of INeuron pointers to point to the
		various neurons in the layer.
*/

#include "ILayer.h"



// PUBLIC FUNCTIONS

/*
	Function Name: getNeurons
	Type: vector<INeuron*>
	Description:  Retrieve the neuron array which represents the neurons 
		contained within the layer.
*/
vector<INeuron*> ILayer::getNeurons() { return neurons; }




/*
	Function Name: getNeuron
	Type: INeuron*
	Parameters: int index
	Parameter Description: An index correlating to the position of the 
		neuron in the layer.
	Description: Given a desired index, this function will return the 
		corresponding INeuron pointer.
*/
INeuron* ILayer::getNeuron(unsigned short index) {
	return neurons[index];
}



/*
	Function Name: getNumOfNeurons
	Type: unsigned short
	Description: Returns the amounts of neurons held within the layer.
*/
unsigned short ILayer::getNumOfNeurons() { return neurons.size(); }
