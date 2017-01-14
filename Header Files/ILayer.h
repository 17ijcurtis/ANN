/*
Author: Isaiah Curtis
Date: 1/10/2017
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
	INeuron * getNeuron(int);

	unsigned short getNumOfNeurons();
};

#endif // !LAYER_H
