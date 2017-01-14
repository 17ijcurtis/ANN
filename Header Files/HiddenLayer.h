/*
	Author: Isaiah Curtis
	Date: 1/13/2017
*/

#pragma once
#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H

#include "ILayer.h"
#include "Neuron.h"
#include "Signal.h"

class HiddenLayer : public ILayer {
public:
	HiddenLayer(unsigned short, ILayer*);
};

#endif // !HIDDENLAYER_H
