/*
	Author: Isaiah Curtis
	Date: 1/10/2017
*/

#pragma once
#ifndef NEURALNET_H
#define NEURALNET_H

#include <iostream>
#include <vector>
using namespace std;

#include "Neuron.h"

#include "ILayer.h"
#include "InputLayer.h"
#include "Layer.h"

#include "EnumsANN.h"

class NeuralNet {
private:
	// Array of layers
	vector<ILayer*> layers;

	double learningRate;
	CostFunctions costFunction;
public:
	NeuralNet(vector<unsigned short>, double, CostFunctions);
	~NeuralNet();

	vector<double> getOutput(vector<double>);
	double getTotalCost(vector<double>, vector<double>);
	double getCost(double, double);
	Layer* getOutputLayer();

	void trainNetwork(vector<double>, vector<double>);
	void calculateNeuronError(vector<double>, vector<double>);
	void calculateWeightGradients();
	void adjustBiases();
	void adjustWeights();
	double sigmoidPrime(double z) { return pow(exp(1.0), -z) / pow(1 + pow(exp(1.0), -z), 2); }
};

#endif