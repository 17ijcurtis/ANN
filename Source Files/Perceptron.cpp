/*
Author: Isaiah Curtis
Date: 12/23/2016
*/

#include "Perceptron.h"

Perceptron::Perceptron() { inputSignal = 0.0; }
Perceptron::Perceptron(double input) { inputSignal = input; }
void Perceptron::setInput(double input) { inputSignal = input; }

double Perceptron::activate() { return sigmoid(inputSignal); }