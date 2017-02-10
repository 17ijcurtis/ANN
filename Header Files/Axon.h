#pragma once

#ifndef AXON_H
#define AXON_H

#include <vector>
using namespace std;

class INeuron;
class Synapse;

struct Axon {
	vector<INeuron*> childNeurons;
	vector<Synapse*> childSynapses;
};

#endif // !AXON_H