/*
	this code for defining an array of doubles, it's for convinience
*/

#ifndef DOUBLEARR
#define DOUBLEARR

typedef struct double_array {
	int l;
	double* data;
} da;

// returns a double array
da* getDa(int len);

// returns a zero initialized double array
da* getDaZero(int len);

// returns a double array with random values between 0 and 1
da* getDaRandom(int len);

// returns a copy of the array 'src'
da* copyDa(farr* src);

// prints all values in farr
void printDa(da* a);

// returns the ith element, if i is out of bounds it prints an error message and returns zero
double daGet(da* a, int i);

// sets the ith element to f, if i is out of bounds it prints an error message 
void daSet(da* a, int i, double f);

#endif
