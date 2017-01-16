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
	NeuralNet ann({ 2, 1 }, 0.5);

	vector<vector<double>> inputs = { {0, 0},
					   {0, 1},
					   {1, 0},
					   {1, 1} };
	vector<vector<double>> outputs = { {0}, {0}, {0}, {1} };

	cout << "Output of Network: " << ann.getOutput({ 1.0, 1.0 })[0] << endl;
	cout << "Cost of Network: " << ann.getCost({ ann.getOutput({ 1.0, 1.0 })[0] }, { 1.0 }) << endl;
	ann.trainAndLearn({ 1.0, 1.0 }, { 1.0 });
	cout << "Output of Network (2nd Iteration): " << ann.getOutput({ 1.0, 1.0 })[0] << endl;
	cout << "Cost of Network (2nd Iteration): " << ann.getCost({ ann.getOutput({ 1.0, 1.0 })[0] }, { 1.0 }) << endl;

	ann.trainAndLearn({ 1.0, 1.0 }, { 1.0 });
	cout << "Output of Network (2nd Iteration): " << ann.getOutput({ 1.0, 1.0 })[0] << endl;
	cout << "Cost of Network (2nd Iteration): " << ann.getCost({ ann.getOutput({ 1.0, 1.0 })[0] }, { 1.0 }) << endl;

	for (int i = 0; i < 50; i++) {
		int randNum = rand() % 4;
		ann.trainAndLearn(inputs[randNum], outputs[randNum]);
	}

	cout << "Output of Network (Finished): " << ann.getOutput({ 1.0, 1.0 })[0] << endl;
	cout << "Cost of Network (Finished): " << ann.getCost({ ann.getOutput({ 1.0, 1.0 })[0] }, { 1.0 }) << endl;
	cout << "Output of Network (Finished): " << ann.getOutput({ 1.0, 0.0 })[0] << endl;
	cout << "Cost of Network (Finished): " << ann.getCost({ ann.getOutput({ 1.0, 0.0 })[0] }, { 0.0 }) << endl;
	cout << "Output of Network (Finished): " << ann.getOutput({ 0.0, 1.0 })[0] << endl;
	cout << "Cost of Network (Finished): " << ann.getCost({ ann.getOutput({ 0.0, 1.0 })[0] }, { 0.0 }) << endl;
	cout << "Output of Network (Finished): " << ann.getOutput({ 0.0, 0.0 })[0] << endl;
	cout << "Cost of Network (Finished): " << ann.getCost({ ann.getOutput({ 0.0, 0.0 })[0] }, { 0.0 }) << endl;
	cin.get();

	return 0;
}