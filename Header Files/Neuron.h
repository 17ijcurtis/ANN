/*
	Author: Isaiah Curtis
	Date: 12/23/2016
*/

#pragma once
#ifndef NEURON_H
#define NEURON_H

#include "INeuron.h"
#include "Synapse.h"

class Neuron : public INeuron {
private:
	// Signal array
	vector<Synapse*> synapses;
	double * biasPointer;
public:
	Neuron(vector<Synapse*>, double*);

	virtual double activate();
	virtual double contents();

	virtual void updateSignalStrength();

	vector<Synapse*> getSynapses();
};

#endif