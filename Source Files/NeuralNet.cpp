/*
	Author: Isaiah Curtis
	Date: 1/10/2017

	Description: A class used to initialize a basic neural network by specifying given dimensions
	A more custom neural network may still be created but it must be done so manually
*/

#include "NeuralNet.h"

// CONSTRUCTOR

// numOfNeuronsPerLayer.size() must be >= 2
NeuralNet::NeuralNet(vector<unsigned short> numOfNeuronsPerLayer, double learningRate) {
	cout << "===============================================================================" << endl;
	cout << "Constructing ANN of dimensions: ";
	for (int i = 0; i < numOfNeuronsPerLayer.size(); i++) {
		cout << numOfNeuronsPerLayer[i] << " ";
	}

	this->learningRate = learningRate;
	
	cout << endl << "Reserving memory for layers... ";
	layers.reserve(numOfNeuronsPerLayer.size());
	cout << "Done." << endl;

	cout << "Creating layers... ";
	for (int i = 0; i < numOfNeuronsPerLayer.size(); i++) {
		if (i == 0) {
			// Input Layer
			layers.push_back(new InputLayer(numOfNeuronsPerLayer[i]));
		} else if (i == numOfNeuronsPerLayer.size() - 1) {
			// Output Layer
			layers.push_back(new OutputLayer(numOfNeuronsPerLayer[i], layers[i - 1]));
		} else {
			// Hidden Layer
			layers.push_back(new HiddenLayer(numOfNeuronsPerLayer[i], layers[i - 1]));
		}
	}
	cout << "Done." << endl;
	cout << "===============================================================================" << endl;
}

vector<double> NeuralNet::getOutput(vector<double> input) {
	// Start at input and go forward through network
	static_cast<InputLayer*>(layers[0])->setInputs(input);

	// Filter through layers and update signals
	for (int i = 1; i < layers.size(); i++) {
		vector<INeuron*> temp = layers[i]->getNeurons();

		for (int j = 0; j < temp.size(); j++) {
			temp[j]->updateSignalStrength();
		}
	}

	int numOfNeuronsInOutput = layers[layers.size() - 1]->getNumOfNeurons();

	vector<double> output;
	output.reserve(numOfNeuronsInOutput);

	// populate output array
	for (int i = 0; i < numOfNeuronsInOutput; i++) {
		output.push_back(layers[layers.size() - 1]->getNeuron(i)->activate());
	}

	return output;
}

// Assumes both emittedOutput and expectedOutput have equivalent size
// Todo in future: Make available multiple cost functions
double NeuralNet::getCost(vector<double> emittedOutput, vector<double> expectedOutput) {
	double cost = 0;
	for (int i = 0; i < emittedOutput.size(); i++)
		cost += pow(expectedOutput[i] - emittedOutput[i], 2) / 2;
	return cost;
}

// Uses back propogation to adjust weights and biases of the network
void NeuralNet::trainAndLearn(vector<double> input, vector<double> expectedOutput) {
	// calculate error gradient of every neuron and adjust weights and biases
	// accordingly

	// First calculate errors in output layer
	vector<double> output = getOutput(input);
	vector<double> biasGradients(layers.size());
	vector<vector<double>> weightGradients(layers.size());

	// A number commonly used in the next loop so I created a variable for it
	int outputLayerIndex = layers.size() - 1;
	double outputLayerError = 0;
	for (int i = 0; i < output.size(); i++) {
		layers[outputLayerIndex]->getNeuron(i)->setError(
			layers[outputLayerIndex]->getNeuron(i)->activate() * 
			(1 - layers[outputLayerIndex]->getNeuron(i)->activate()) *
			(output[i] - expectedOutput[i]));

		// The bias gradients of each respective neuron in the output layer is equal to the error
		outputLayerError += pow(layers[outputLayerIndex]->getNeuron(i)->getError(), 2);
	}

	outputLayerError = sqrt(outputLayerError);
	biasGradients[outputLayerIndex] = outputLayerError;


	// Now that the error within the output neurons has been calculated we 
	// now have to calculate the weight gradients for each incoming signal
	for (int i = 0; i < layers[outputLayerIndex]->getNumOfNeurons(); i++) {
		vector<Signal*> temp = static_cast<Neuron*>(layers[outputLayerIndex]->getNeuron(i))->getSignals();

		for (int j = 0; j < temp.size(); j++)
			weightGradients[outputLayerIndex].push_back(temp[j]->getSignalStrength() * 
				layers[outputLayerIndex]->getNeuron(i)->getError());
	}


	// Change weights and biases according to gradients

	// Changing biases within output layer
	static_cast<OutputLayer*>(layers[outputLayerIndex])->setBias(
		static_cast<OutputLayer*>(layers[outputLayerIndex])->getBias() - 
		learningRate * biasGradients[outputLayerIndex]);

	// Change weights within output layer
	for (int i = 0; i < layers[outputLayerIndex]->getNumOfNeurons(); i++) {
		vector<Signal*> temp = static_cast<Neuron*>(layers[outputLayerIndex]->getNeuron(i))->getSignals();

		for (int j = 0; j < temp.size(); j++)
			temp[i]->updateWeight(temp[i]->getSignalWeight() - learningRate * weightGradients[outputLayerIndex][i]);
	}
}