/*
	Author: Isaiah Curtis
	Date: 1/10/2017

	Description: A class used to initialize a basic neural network by specifying given dimensions
	A more custom neural network may still be created but it must be done so manually
*/

#include "NeuralNet.h"






/*
	CONSTRUCTOR
	Parameters: vector<unsigned short> numOfNeuronsPerLayer, 
		double learningRate, CostFunctions costFunction
	Parameter Description: numOfNeuronsPerLayer is simply a vector array 
		contains the number of neurons to be created in each layer of the
		network.  The user must also pass the initial learning rate for the 
		network, as well as the cost function that the network will use to 
		calculate the gradients for backpropogation.
	Description: The constructor takes the parameters and constructs a neural
		network of the indicated dimensions.  It uses cout to briefly narrate
		the process of the creation of the network.
*/
NeuralNet::NeuralNet(vector<unsigned short> numOfNeuronsPerLayer, double learningRate, CostFunctions costFunction) {
	cout << "===============================================================================" << endl;
	cout << "Constructing ANN of dimensions: ";
	for (int i = 0; i < numOfNeuronsPerLayer.size(); i++) {
		cout << numOfNeuronsPerLayer[i] << " ";
	}

	this->learningRate = learningRate;
	this->costFunction = costFunction;

	cout << endl << "Reserving memory for layers... ";
	layers.reserve(numOfNeuronsPerLayer.size());
	cout << "Done." << endl;

	cout << "Creating layers... ";
	for (int i = 0; i < numOfNeuronsPerLayer.size(); i++) {
		if (i == 0) layers.push_back(new InputLayer(numOfNeuronsPerLayer[i]));				// Input Layer
		else layers.push_back(new Layer(numOfNeuronsPerLayer[i], layers[i - 1]));			// Standard Layer
	}

	cout << "Done." << endl;
	cout << "===============================================================================" << endl;
}



/*
	DESTRUCTOR
	Description: Deallocate all memory reserved for the layer pointers
*/
NeuralNet::~NeuralNet() {
	for (ILayer * layer : layers)
		delete layer;
}



// PUBLIC FUNCTIONS


/*
	Function Name: getOutput
	Type: vector<double>
	Parameters: vector<double> input
	Parameter Description: The input to be fed into the network.
	Description:  The input is first fed into the first layer of the network.
		Then the program loops through layers and updates the signal strength
		of each synapse to each neuron.  Then make an output array of length 
		equal to the amount of neurons in the output layer and populate its
		values.
*/
vector<double> NeuralNet::getOutput(vector<double> input) {

	static_cast<InputLayer*>(layers[0])->setInputs(input);

	for (int i = 1; i < layers.size(); i++)
		for (INeuron* neuron : layers[i]->getNeurons())
			neuron->updateSignalStrength();

	int numInOutput = layers[layers.size() - 1]->getNumOfNeurons();

	vector<double> output;
	output.reserve(numInOutput);

	for (int i = 0; i < numInOutput; i++) 
		output.push_back(layers[layers.size() - 1]->getNeuron(i)->activate());

	return output;
}



/*
	Function Name: getTotalCost
	Type: double
	Parameters: vector<double> emittedOutput, vector<double> expectedOutput
	Parameter Description:  The two vector arrays are the outputs emitted by
		the network and the output that was desired, or expected to emitted,
		respectively.
	Description: This function compares the two output arrays and determines
		the net error within the neural network.
*/
double NeuralNet::getTotalCost(vector<double> emittedOutput, vector<double> expectedOutput) {
	double cost = 0;

	for (int i = 0; i < emittedOutput.size(); i++) {
		cost += getCost(emittedOutput[i], expectedOutput[i]);
	}

	return cost;
}



/*
	Function Name: getCost
	Type: double
	Parameters: double emittedOutput, double expectedOutput
	Parameter Description: A value emitted from one of the output neurons that 
		must be compared with the desired or expected output to calculate an 
		error.
	Description: Depending on the decided cost function, a cost/error is 
		calculated and returned.
*/
double NeuralNet::getCost(double emittedOutput, double expectedOutput) {
	switch (costFunction) {
	case COST_STANDARD:
		return pow(expectedOutput - emittedOutput, 2) / 2;
	}
	return 0;
}