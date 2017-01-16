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
	virtual double activate();
	virtual double contents();
	virtual void updateSignalStrength();
	void setInput(double);
};

#endif