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
private:
	double * bias;
public:
	HiddenLayer(unsigned short, ILayer*);
	double getBias();
	void setBias(double bias);
};

#endif // !HIDDENLAYER_H
