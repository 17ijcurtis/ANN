# ANN
An Artificial Neural Networking library

As of now there are no training methods so the network cannot learn, but fear not, they are on the way.
In order to initialize a network and run data through it simply do the following:

<code>
NeuralNet myNetwork(vector\<unsigned short> theNumberOfNeuronsYouWantPerRow, double learningRate, CostFunctions desiredCostFunction);
</code>

And then to find the output of the network given a specific input, simple use:

<code>
myNetwork.getOutput(vector\<double> inputArray);
</code>

The getOutput function returns a vector with each element corresponding to an output neuron.
