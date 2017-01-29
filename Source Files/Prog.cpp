/*
Author: Isaiah Curtis
Date: 1/10/2017
*/

#include "Prog.h"

/*
	TODO:
	create deconstructors for all classes to avoid memory leaks
	change all pointer arrays to vector arrays
	delete pointers!!! lol
*/

int main() {
	NeuralNet ann({ 2, 1 }, 0.5, COST_STANDARD);
	cout << "Output of network " << ann.getOutput({ 1.0, 1.0 })[0] << endl;
	cout << "Cost of network " << ann.getTotalCost(ann.getOutput({ 1.0, 1.0 }), { 1.0 }) << endl;
	cin.get();

	return 0;
}