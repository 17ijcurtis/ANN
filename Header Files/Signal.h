/*
	Author: Isaiah Curtis
	Date: 12/23/2016
*/

#pragma once
#ifndef SIGNAL_H
#define SIGNAL_H

#include "INeuron.h"

class Signal {
private:
	double signalStrength;
	double signalWeight;

	// The neuron from which the signal was sent
	INeuron* sender;

public:
	Signal(INeuron &obj, double weight) {
		updateWeight(weight);
		sender = &obj;
	}

	double getWeightedSignal();
	
	// Updating Functions
	void updateStrength(double);
	void updateWeight(double);

	INeuron * getParentNeuron();

	// Accessor Functions
	double getSignalStrength() const { return signalStrength; }
	double getSignalWeight() const { return signalWeight; }
};

#endif