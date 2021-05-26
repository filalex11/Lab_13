#ifndef BINVECT_CPP
#define BINVECT_CPP
#include <stdio.h>
#include "BinVect.h"
BinVect :: BinVect (int s) {
	if (s < 1) {
		printf ("ERROR! SIZE OF BINARY VECTOR MUST BE MORE THAN 1!\n");
		return;
	}
	size = s;
	vector = new char[size];
}

BinVect :: BinVect (void) {
	size = 3;
	vector = new char[size];
}

BinVect :: ~BinVect (void) {
	if (vector) {
		delete [] vector;
	}
}

char BinVect :: input (void) {
	printf ("Enter the components of the vector (%d):\n", size);
	int i = 0;
	char error = 0;
	while (i < size) {
		scanf ("%hhd", &vector[i]);
		if ((vector[i] > 1) || (vector[i] < 0)) {
			error = 1;
		}
		++i;
	}
	if (error) {
		delete [] vector;
		vector = new char[size];
		return 1;
	}
	return 0;
}

void BinVect :: output (void) {
	printf ("Componenets of the vector:\n");
	int i = 0;
	while (i < size) {
		printf ("%d ", vector[i++]);
	}
	printf ("\n");
}

BinVect& BinVect :: operator = (BinVect &v) {
	if (&v == this) {
		return *this;
	}
	if (size < v.size) {
		size = v.size;
	}
	delete [] vector;
	vector = new char[size];
	int i = 0;
	for (i = 0; i < size; ++i) {
		if (i < v.size) {
			vector[i] = v.vector[i];
		} else {
			vector[i] = 0;
		}
	}
	return *this;
}

BinVect& BinVect :: operator + (BinVect &v) {
	int i = 0;
	char rank = 0;
	this->size > v.size ? v.size = this->size : this->size = v.size;
	for (i = size - 1; i >= 0; --i) {
		vector[i] += v.vector[i] + rank;
		rank = 0;
		if (vector[i] > 1) {
			vector[i] %= 2;
			rank++;
		}
		if ((i == 0) && (rank)) {
			char tmp[size];
			int j = 0;
			for (j = 0; j < size; j++) {
				tmp[j] = vector[j];
			}
			delete [] vector;
			vector = new char[++size];
			vector[0] = 1;
			int k = 1;
			for (j = 0; j < size; j++) {
				vector[k++] = tmp[j];
			}
		}
	}
	return *this;
}

BinVect& BinVect :: operator += (BinVect &v) {return *this;}









#endif
