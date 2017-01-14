# ANN
An Artificial Neural Networking library

As of now there are no training methods so the network cannot learn, but fear not, they are on the way.
In order to initialize a network and run data through it simply do the following:

NeuralNet myNetwork(vector\<unsigned short> theNumberOfNeuronsYouWantPerRow);

And then to find the output of the network given a specific input, simple use:

myNetwork.getOutput(vector\<double> inputArray);

The getOutput function returns a vector with each element corresponding to an output neuron.
