/*
	Author: Isaiah Curtis
	Date: 1/13/2017
*/

#pragma once
#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H

#include "ILayer.h"
#include "Neuron.h"
#include "Signal.h"

class OutputLayer : public ILayer {
private:
	double * bias;
public:
	OutputLayer(unsigned short, ILayer*);
	double getBias();
	void setBias(double);
};

#endif // !OUTPUTLAYER_H
