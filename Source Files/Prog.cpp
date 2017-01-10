/*
Author: Isaiah Curtis
Date: 1/10/2017
*/

#include "Prog.h"

/*
	TODO:
	create deconstructors for various classes
*/

int main() {
	Perceptron perceptron1(1.0);
	Perceptron perceptron2(1.0);

	Signal signalArray[] = { Signal(perceptron1, 1.0), Signal(perceptron2, 1.0) };

	Neuron Neuron1(signalArray, sizeof(signalArray) / sizeof(*signalArray));

	cout << Neuron1.activate();

	cin.get();

	return 0;
}