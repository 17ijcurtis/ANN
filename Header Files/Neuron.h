/*
	Author: Isaiah Curtis
	Date: 12/23/2016
*/

#pragma once
#ifndef NEURON_H
#define NEURON_H

#include "INeuron.h"
#include "Signal.h"

class Neuron : public INeuron {
private:
	// Signal array
	vector<Signal*> signals;

	double contents();
	void updateSignalStrengths();

public:
	Neuron(vector<Signal*>s);
	virtual double activate();
};

#endif