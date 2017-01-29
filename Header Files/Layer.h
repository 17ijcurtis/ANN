/*
	Author: Isaiah Curtis
	Date: 1/13/2017
*/

#pragma once
#ifndef LAYER_H
#define LAYER_H

#include "ILayer.h"
#include "Neuron.h"
#include "Synapse.h"

class Layer : public ILayer {
private:
	double * bias;
public:
	Layer(unsigned short, ILayer*);
	~Layer();

	double getBias();
	void setBias(double bias);
};

#endif // !LAYER_H
