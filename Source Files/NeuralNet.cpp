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
	Parameters:vector<double> expectedOutput, vector<double> emittedOutput
	Parameter Description:  The two vector arrays are the outputs emitted by
		the network and the output that was desired, or expected to emitted,
		respectively.
	Description: This function compares the two output arrays and determines
		the net error within the neural network.
*/
double NeuralNet::getTotalCost(vector<double> expectedOutput, vector<double> emittedOutput) {
	double cost = 0;

	for (int i = 0; i < emittedOutput.size(); i++) {
		cost += getCost(emittedOutput[i], expectedOutput[i]);
	}

	return cost;
}



/*
	Function Name: getCost
	Type: double
	Parameters: double expectedOutput, double emittedOutput
	Parameter Description: A value emitted from one of the output neurons that 
		must be compared with the desired or expected output to calculate an 
		error.
	Description: Depending on the decided cost function, a cost/error is 
		calculated and returned.
*/
double NeuralNet::getCost(double expectedOutput, double emittedOutput) {
	switch (costFunction) {
	case COST_STANDARD:
		return pow(expectedOutput - emittedOutput, 2) / 2;
	}
	return 0;
}



/*
	Function Name: getOutputLayer
	Type: Layer*
	Description: Returns the output layer of the neural network
*/
Layer* NeuralNet::getOutputLayer() { return static_cast<Layer*>(layers[layers.size() - 1]); }



/*
	Function Name: trainNetwork
	Type: void
	Parameters: vector<double> input, vector<double> expectedOutput
	Parameter Description:
	Description:
*/
int iterationsInEpoch = 0;

void NeuralNet::trainNetwork(vector<double> input, vector<double> expectedOutput) {
	vector<double> output = getOutput(input);

	iterationsInEpoch++;

	calculateNeuronError(expectedOutput, output);
	calculateWeightGradients();
	if (iterationsInEpoch > 10) {
		adjustBiases();
		adjustWeights();
		iterationsInEpoch = 0;
	}
}

/*
	Function Name: calculateNeuronError
	Type: void
	Parameters: vector<double> expectedOutput, vector<double> output
	Parameter Description: The output that we wish our network to emit and the
		output that
*/
void NeuralNet::calculateNeuronError(vector<double> expectedOutput, vector<double> output) {
	// Calculate errors in the output layer
	for (int i = 0; i < getOutputLayer()->getNumOfNeurons(); i++) {
		getOutputLayer()->getNeuron(i)->setError((output[i] - expectedOutput[i]) * output[i] * (1 - output[i]));
		//cout << "output neuron index:" << i << ",error:" << getOutputLayer()->getNeuron(i)->getError() << endl;
	}

	// We dont need to calculate the error within the perceptrons because they are simply
	// for input.
	int layerIndex = layers.size() - 2;		// The layer before the output layer

	// loop through layers
	for (int i = layerIndex; i > 0; i--) {
		// loop through neurons in each layer
		for (int j = 0; j < layers[layerIndex]->getNumOfNeurons(); j++) {
			double error = 0;
			for (int k = 0; k < layers[layerIndex + 1]->getNumOfNeurons(); k++) {
				error += layers[layerIndex + 1]->getNeuron(k)->getError() * 
						static_cast<Neuron*>(layers[layerIndex + 1]->getNeuron(k))->getSynapses()[j]->getWeight();
			}

			layers[i]->getNeuron(j)->setError((error * layers[layerIndex]->getNeuron(j)->activate() * (1 - layers[layerIndex]->getNeuron(j)->activate())
				+ layers[i]->getNeuron(j)->getError()) / 2);
			//cout << layers[i]->getNeuron(j)->getError() << endl;
			//cout << "neuron layer:" << i << ",index:" << j << ",error:" << error << endl;
		}
	}
}

/*
	Function Name: calculateWeightGradients
	Type: void
	Description:
*/
void NeuralNet::calculateWeightGradients() {
	// for output later
	for (int i = 0; i < getOutputLayer()->getNumOfNeurons(); i++) {
		Neuron* temp = static_cast<Neuron*>(getOutputLayer()->getNeuron(i));
		for (int j = 0; j < temp->getSynapses().size(); j++) {
			temp->getSynapses()[j]->setWeightGradient(temp->getSynapses()[j]->getParentNeuron()->activate() * 
				getOutputLayer()->getNeuron(i)->getError());
		}
	}
	
	// layers
	for (int i = layers.size() - 2; i > 0; i--) {
		// neurons
		for (int j = 0; j < layers[i]->getNumOfNeurons(); j++) {
			// Loop through synapses and make weight gradients
			Neuron* temp = static_cast<Neuron*>(layers[i]->getNeuron(j));
			// synapses
			for (int k = 0; k < temp->getSynapses().size(); k++) {
				double gradient = 0;

				for (int l = 0; l < temp->getAxon()->childSynapses.size(); l++) {
					gradient += temp->getAxon()->childSynapses[l]->getWeight() *
 						temp->getAxon()->childNeurons[l]->getError();
				}

				temp->getSynapses()[k]->setWeightGradient(temp->getSynapses()[k]->getParentNeuron()->activate() *
					gradient *
					layers[i]->getNeuron(j)->activate() *
					(1 - layers[i]->getNeuron(j)->activate()));
			}
		}
	}
}



/*
	Function: calculateBiasGradients
	Type: void
	Description:
*/
void NeuralNet::adjustBiases() {
	for (int i = layers.size() - 1; i > 0; i--) {
		// Adjust biases
		for (int j = 0; j < layers[i]->getNumOfNeurons(); j++) {
			static_cast<Neuron*>(static_cast<Layer*>(layers[i])->getNeuron(j))->adjustBias(-learningRate*
				layers[i]->getNeuron(j)->getError());
		}
	}
}



/*
	Function: adjustWeights
	Type: void
	Description:
*/
void NeuralNet::adjustWeights() {
	for (int i = layers.size() - 1; i > 0; i--) {
		for (int j = 0; j < layers[i]->getNumOfNeurons(); j++) {
			// Loop through synapses and update weight gradients
			for (int k = 0; k < static_cast<Neuron*>(layers[i]->getNeuron(j))->getSynapses().size(); k++) {
				static_cast<Neuron*>(layers[i]->getNeuron(j))->getSynapses()[k]->setWeight(
					static_cast<Neuron*>(layers[i]->getNeuron(j))->getSynapses()[k]->getWeight() - 
					learningRate * static_cast<Neuron*>(layers[i]->getNeuron(j))->getSynapses()[k]->getWeightGradient());
			}
		}
	}
}