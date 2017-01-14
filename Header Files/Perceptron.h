/*
Author: Isaiah Curtis
Date: 1/10/2017
*/

#pragma once
#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "INeuron.h"

class Perceptron : public INeuron {
private:
	double inputSignal;
	double * biasPointer;
public:
	Perceptron(double*);

	virtual double activate();
	void setInput(double);
};

#endif