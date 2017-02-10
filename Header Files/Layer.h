/*
	Author: Isaiah Curtis
	Date: 1/13/2017
*/

#pragma once
#ifndef LAYER_H
#define LAYER_H

#include "ILayer.h"
#include "Synapse.h"
#include "Neuron.h"

class Layer : public ILayer {
public:
	Layer(unsigned short, ILayer*);
	~Layer();
};

#endif // !LAYER_H
