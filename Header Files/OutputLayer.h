/*
	Author: Isaiah Curtis
	Date: 1/13/2017
*/

#pragma once
#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H

#include "ILayer.h"
#include "Receptron.h"
#include "Signal.h"

class OutputLayer : public ILayer {
public:
	OutputLayer(unsigned short, ILayer*);
	vector<double> getOutput();
};

#endif // !OUTPUTLAYER_H
