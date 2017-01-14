/*
Author: Isaiah Curtis
Date: 1/10/2017
*/

#include "Prog.h"

/*
	TODO:
	create deconstructors for all classes to avoid memory leaks
	change all pointer arrays to vector arrays
*/

int main() {
	NeuralNet ann({ 2, 1 });
	cout << ann.getOutput({ 1.0, 2.0 })[0];

	cin.get();

	return 0;
}