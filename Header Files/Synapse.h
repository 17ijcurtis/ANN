/*
	Author: Isaiah Curtis
	Date: 12/23/2016
*/

#pragma once

#ifndef SYNAPSE_H
#define SYNAPSE_H

#include "INeuron.h"

class Synapse {
private:
	double strength;
	double weight;

	// The neuron from which the signal was sent
	INeuron* parentNeuron;

	double weightGradient;

public:
	Synapse(INeuron*, double);

	INeuron* getParentNeuron();

	double getStrength();
	double getWeight();
	double getWeightedSignal();
	double getWeightGradient();

	void updateStrength();
	void setWeight(double);
	void setWeightGradient(double);
};

#endif // !SYNAPSE_H