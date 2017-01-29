/*
	Author: Isaiah Curtis
	Date: 1/10/2017
	Description: An abstract layer class from which all other layer classes are
		derived.  It contains a vector of INeuron pointers to point to the
		various neurons in the layer.
*/

#pragma once
#ifndef ILAYER_H
#define ILAYER_H

#include "INeuron.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class ILayer {
protected:
	// array for neurons contained within the layer
	vector<INeuron*> neurons;
public:
	// Perceptron layer constructor
	vector<INeuron*> getNeurons();
	INeuron * getNeuron(unsigned short);

	unsigned short getNumOfNeurons();
};

#endif // !LAYER_H
