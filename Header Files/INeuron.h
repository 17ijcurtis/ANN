/*
Author: Isaiah Curtis
Date: 1/10/2017
*/


//The following is a skeleton neuron that will be
//used by both the perceptron and neuron class

#pragma once
#ifndef INEURON_H
#define INEURON_H

#include <cmath>
#include <vector>

using namespace std;

class INeuron {
private:
	const double eulerConstant = exp(1.0);
protected:
	double sigmoid(double z) { return 1.0 / (1.0 + pow(eulerConstant, -z)); }
public:
	virtual double activate() = 0;
};

#endif