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

public:
	Synapse(INeuron*, double);

	INeuron * getParentNeuron();

	double getStrength();
	double getWeight();
	double getWeightedSignal();

	void updateStrength();
	void setWeight(double);
};

#endif // SYNAPSE_H