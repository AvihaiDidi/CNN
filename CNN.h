/*
	most important file of this project
	the C stands for C. This isn't a convulutional NN.
	
	as of right now it only supports fully connected layers with relu activation functions
	might go back and implement other stuff later if I feel like it
	
	if the output_width is greater than one, the last layer is a softmax for training and a max for testing / evaluating
*/

#ifndef CNN
#define CNN

import da.h;

typedef struct neural_network {
	int input_width;
	da* weights;
	da* biases;
	int output_width;
} CNN;

/*	returns a CNN struct
hidden count is the number of hidden layers and hidden_widths is their widths	*/
CNN* initCNN(int input_width, int output_width, int hidden_count, int* hidden_widths);

// uses the data in path to train the network
// 'path' should point towards a .csv file
// if verbose is the letter T (True), it prints info about the training process
void train(CNN* nn, char* path, char verbose);

// uses the data in path to test the network
// returns the MSE (Mean Ssquare Error)
double testCNN(CNN* nn, char* path);

// runs input through the network
// note that the input array MUST have the same length as the one defined in initCNN
double* evaluate(CNN* nn, double* in);

#endif
