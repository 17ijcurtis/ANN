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
public:
	Perceptron();
	Perceptron(double);
	void setInput(double);

	virtual double activate();
};

#endif