/*
	Author: Isaiah Curtis
	Date: 1/11/2017
*/

#pragma once
#ifndef RECEPTRON_H
#define RECEPTRON_H

#include "INeuron.h"
#include "Signal.h"

class Receptron : public INeuron {
private:
	// Signal array
	vector<Signal*> signals;

	virtual void updateSignalStrengths();

public:
	Receptron(vector<Signal*>);
	virtual double activate();
};

#endif // !RECEPTRON_H
