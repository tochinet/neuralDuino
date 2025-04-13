# neuralDuino
neuralDuino (small n) is an Arduino library for Artificial Neural Networks, [created by Pranav Gulati](https://github.com/Pranavgulati/neuralDuino) in February 2017 and featured on [Hackaday](http://bit.ly/neuralDuino_H). Its originality resides in the absence of "layers" (input, inner, output). Instead, each neuron object simply has synapses incoming to it and a single output available to other neurons. In addition, connections can be dynamically modified.

Because the Arduino boards have limited memory, the library has been adapted to use Posit arithmetic (8 or 16-bit) instead of 32-bit floats. This not only reduces memory usage, but also speeds up operations as many architectures have no floating point hardware accelerator.

# Principles
- The neuralDuino library structures neural networks as a set of connected individual neurons, without the concept of layers. Most other libraries think of neural networks as layers of nodes (input, inner, output).
- Back-propagation is atomic : the backpropagate method is called on each neuron and backpropagates the beta to all the neurons that *this* neuron is connected to.
- This design principle should give the flexibility to create any kind of ANN architecture (perceptron, transformers, RNN, LTSM, ...) or even cascaded Neural Networks with the same API.

# Instructions
- Start with the examples, read the comments and move from there
- For any problems post an issue
- Fork and contribute back. That's the spirit of GitHub

# Pre-Requisites
- Tested using Arduino v1.6.5(windows) on UNO and Mega but should be easily ported to other architectures as it is plain C++.

# Features
- choose your own activation function from the main sketch for each neuron individually
- each neuron is an object and whatever network you draw on the paper can be realized with this library
- Layer management (Construction and connections) given to the user with a default back-propagation and adjWeights implementation that needs to be called by the programmer as and when they wish.
- Lots of examples with different neural net architectures ;-P

Read the story on hackaday - http://bit.ly/neuralDuino_H
