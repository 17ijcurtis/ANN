/*
	Author: Isaiah Curtis
	Date: 1/11/2017
*/

#pragma once
#ifndef INPUTLAYER_H
#define INPUTLAYER_H

#include "ILayer.h"
#include "Perceptron.h"

class InputLayer : public ILayer {
public:
	InputLayer(unsigned short);
	void setInputs(vector<double>);
};

#endif // !INPUTLAYER_H
