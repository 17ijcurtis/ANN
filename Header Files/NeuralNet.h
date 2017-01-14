/*
	Author: Isaiah Curtis
	Date: 1/10/2017
*/

#pragma once
#ifndef NEURALNET_H
#define NEURALNET_H

#include <cmath>
#include <iostream>
#include <vector>

#include "ILayer.h"
#include "INeuron.h"

#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"

using namespace std;

class NeuralNet {
private:
	// Array of layers
	vector<ILayer*> layers;
public:
	NeuralNet(vector<unsigned short>);

	vector<double> getOutput(vector<double>);
	double getCost(vector<double>, vector<double>);
};

#endif