/*
	Author: Isaiah Curtis
	Date: 1/10/2017
	Description: The following is a skeleton neuron that will be used by both the 
		perceptron and neuron class
*/


#pragma once

#ifndef INEURON_H
#define INEURON_H

#include <cmath>>
#include "Axon.h";

class INeuron {
private:
	const double eulerConstant = exp(1.0);
	double error;
	Axon* axon;
protected:
	// Activation Functions
	double sigmoid(double z) { return 1.0 / (1.0 + pow(eulerConstant, -z)); }
public:
	INeuron() { this->initAxon(); error = (rand() / double(RAND_MAX)) - .5; }
	~INeuron() { delete axon; }
	virtual double activate() = 0;
	virtual double contents() = 0;
	virtual void updateSignalStrength() = 0;
	double getError() { return error; }
	void setError(double error) { this->error = error; }

	void initAxon() { axon = new Axon(); }
	Axon* getAxon() { return axon; }
};


#endif // !INEURON_H