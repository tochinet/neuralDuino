# neuralDuino
neuralDuino (small n) is an Arduino library for Artificial Neural Networks, [created by Pranav Gulati](https://github.com/Pranavgulati/neuralDuino) in February 2017 and featured on [Hackaday](http://bit.ly/neuralDuino_H). Its originality resides in the absence of "layers" (input, inner, output). Instead, each neuron object simply has synapses incoming to it and a single output available to other neurons. In addition, connections can be dynamically modified. This makes the library very light.

Because the Arduino boards have limited memory, the float calculations are a big part of the load on CPU and RAM. Hence this branch targets an adaptation to use (8 or 16-bit) [Posit arithmetic](https://posithub.org/docs/Posits4.pdf) instead of 32-bit floats. This not only reduces memory usage, but also speeds up operations for the many architectures that have no floating point hardware accelerator (AVR, RP2040, Cortex M0 and M3, ...).
First architecture targeted is the AVR ATmega 328 of the Arduino UNO.

# Design Principles
- The neuralDuino library structures neural networks as a set of connected individual neurons, without the concept of layers (input, inner, output) that are present in almost all other libraries.
- The absence of layers should give the flexibility to create any kind of ANN architecture (perceptron, transformers, RNN, LTSM, ...) or even cascaded Neural Networks with the same API.
- Each neuron is an object and whatever network you draw on the paper can be realized with this library
- Back-propagation is atomic : the backpropagate() method is called on each neuron and backpropagates the beta to all the neurons that *this* neuron is connected to.
- Construction Layer management (Construction and connections) left to the user, with a default back-propagation and adjWeights implementation that needs to be called by the programmer as and when they wish.
- Choice of activation function is also atomic (selected from the main sketch for each neuron individually).

# How to use it
- Start with the examples (including different neural net architectures), read the comments and move from there
- For any problems post an issue
- Fork and contribute back. That's the spirit of GitHub

# Status
- The original library is tested (with floats) using Arduino v1.8.5 on Windows on UNO
- TODO: port to other architectures (should be easy as it is plain C++).

