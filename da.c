/*

	Function documentation (comments) is in the header file
	This file just has the implementations

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "farr.h"

da* getDa(int len) {
	farr* a = malloc(sizeof(farr));
	a->l = len;
	a->data = malloc(sizeof(floar) * len);
	return a;
}

da* getDaZero(int len) {
	farr* a = malloc(sizeof(farr));
	a->l = len;
	a->data = malloc(sizeof(floar) * len);
	for (int i = 0; i < len; i++)
		a->data[i] = 0;
	return a;
}

da* getDaRandom(int len) {
	farr* a = malloc(sizeof(farr));
	a->l = len;
	a->data = malloc(sizeof(floar) * len);
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		a->data[i] = (double)rand() / (double)RAND_MAX;
	return a;
}

da* copyDa(farr* src) {
	da* tar = getDa(src->l);
	for (int i = 0; i < src.l; i++)
		daSet(tar, i, daGet(src, i));
	return tar;
}

void printDa(da* a) {
	for (int i = 0; i < a->l, i++)
		printf("%d\t%lf\n", i, daGet(a, i));
}

double daGet(da* a, int i) {
	if (i < 0 || a->l <= i) {
		printf("Array index provided to daGet is out of range.\n");
		return 0;
	}
	return a->data[i];
}

void daSet(da* a, int i, double f) {
	if (i < 0 || a->l <= i) {
		printf("Array index provided to daSet is out of range.\n");
		return 0;
	}
	a->data[i] = f;
}

