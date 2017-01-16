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

	double learningRate;
public:
	NeuralNet(vector<unsigned short>, double);

	vector<double> getOutput(vector<double>);
	double getCost(vector<double>, vector<double>);

	void trainAndLearn(vector<double>, vector<double>);
	double sigmoidPrime(double z) { return pow(exp(1.0), -z) / pow(1 + pow(exp(1.0), -z), 2); }
};

#endif