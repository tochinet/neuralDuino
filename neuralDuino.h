#ifndef __neuralDuino_h__
#define __neuralDuino_h__

#define FPTYPE float // FPTYPE indicates what is used for calculations. Now still float (32-bit IEEE754)
//#define FPTYPE Posit8
//#define FPTYPE Posit16
#define DEBUG 0
#define DISPLAY_ERROR 1
#define LEARNING_RATE 0.1
#define MOMENTUM 0.1
#define SPEED LEARNING_RATE
#define FALSE LOW
#define TRUE HIGH

#include "Arduino.h"
#define sigmoid(x)           (1.0 / (1.0 + exp(-(x))))
#define sigmoidDerivative(x) (((x)*(1.0-(x)))) 

/* types of neurons can be classified using the 2 begin() parameters noConnections and noInputs

					noConnections	noInputs
	hybrid (most inefficient)	LOW		LOW		(DEFAULT) //leaves the control to the programmer
	intermediate neuron		LOW		HIGH
	bias				HIGH		HIGH
	input neuron			HIGH		LOW

 TODO: too many float calculations consider optimizing /removing these as well
*/

typedef float (*activFn)(float,byte);

class neuron{

public:
	neuron(); //constructor

	float *synWeight; /* synWeight holds the weight of each synapase that is INCOMING for that neuron
	the length of synWeight is decided by the begin() function where mem alloc takes place. */

	float *prevDelWeight;	/*stores the previous change ini weight for each synapse, ONLY required for momentum functionality */

	neuron **inNodes; //array of pointers of type neuron
	float output; // stores the output of this neuron

	float *input; 	/* for a neuron to which no other neurons are connected an input may be specified.
	this implies that neuron will have inputs defined by the user instead of being the output of other neurons */

	/* the second way to have inputs is to have output of some other neurons feed into 
	this neuron inNodes stores the address of every neuron which is connected to this
	neuron and asks for the output from each of those to calculate its output */


	byte inCount ; //input Nodes are only counted 
	/* counts the number of neurons that are connected to this neuron using connectInput()
	Be advised this DOES NOT keep count of the inputs specified by the programmer by the setInput() function */


	byte numSynapse; /* keeps count of the inputs specified by setInput() and begin() 
   this counts the number of float array type inputs and not the connectInput() ones */

	activFn activation; // associates an activation function for this neuron, user sets the address of any activation function using setActivationFn() */

	float beta; // backpropagation constant

	/* to prevent memory fragmentation while retaining flexibility the begin function
	allocates memory one time only, while it is possible to do away with this
	and have completely dynamic alloc and realloc but it is not advisable because the RAM may get
	fragmented

	ARGs:
	noConnections : implies that this neuron will not have any connections coming into it
            when noConnections = HIGH, this doesnt allocate memory for connections
	noInputs : implies that this neuron will not have any float inputs coming into it from the user
            when noInputs = HIGH, this doesnt allocate memory for inputs
	these are optional arguments for those people who know what they are doing  */

	void begin(byte num_syn, byte noConnections = FALSE, byte noInputs = FALSE);
	
	void setInput(float input[]); // Set the constant input values for the input layer
	void setInput(int input[]);
	void setOutput(int value); // Set the constant output value mostly for the bias node only
	byte setDesiredOutput(float desiredOutput); // setDesiredOUtput only valid for the last nodes
	float getOutput(); // get output from the input nodes	
	void setActivationFn(activFn userFn); // set the activation function for this->node
	void printWeights(); // print the final weights after learning has happened
	void adjWeights(); // adjust weights according to the update rule
	void backpropagate(); //backpropagate the betas to the connected nodes only
	
	void connectInput(neuron* inNode); /* connect other nodes to this->node as inputs
	this function accepts one neuron pointer and adds to the list of input pointers
 	from which output is taken as an input for this node */
};





#endif
