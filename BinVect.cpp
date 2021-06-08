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

BinVect :: BinVect (const BinVect &v) {
	size = v.size;
	vector = new char[size];
	int i = 0;
	for (i = 0; i < size; ++i) {
		vector[i] = v.vector[i];
	}
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
		vector[i] = v.vector[i];
	}
	return *this;
}

BinVect BinVect :: operator + (const BinVect &v) const {
	char rank = 0;
	BinVect result (*this);
	if (this->size != v.size) {
		if (this->size > v.size) {
			int j = 0;
			for (int i = 0; i < result.size; ++i) {
				if (i < result.size - v.size) {
					result.vector[i] = 0;
				} else {
					result.vector[i] = v.vector[j];
					++j;
				}
			}
		} else {
			delete [] result.vector;
			result.size = v.size;
			result.vector = new char[result.size];
			int j = 0;
			for (int i = 0; i < result.size; ++i) {
				if (i < (result.size - this->size)) {
					result.vector[i] = 0;
				} else {
					result.vector[i] = this->vector[j];
					++j;
				}
			}
		}
	}
	int i = 0;
			/*printf ("res: %d\n", result.vector[0]);
			printf ("res: %d\n", result.vector[1]);
			printf ("res: %d\n", result.vector[2]);
			printf ("res: %d\n", result.vector[3]);
			printf ("res: %d\n", result.vector[4]);
			printf ("\n");
			printf ("res: %d\n", vector[0]);
			printf ("res: %d\n", vector[1]);
			printf ("res: %d\n", vector[2]);
			printf ("res: %d\n", vector[3]);
			printf ("res: %d\n", vector[4]);*/
	for (i = result.size - 1; i >= 0; --i) {
		if (this->size > v.size) {
			result.vector[i] += this->vector[i] + rank;
		} else {
			result.vector[i] += v.vector[i] + rank;
		}
		rank = 0;
		if (result.vector[i] > 1) {
			result.vector[i] %= 2;
			rank++;
		}
		if ((i == 0) && (rank)) {
			char tmp[result.size];
			for (int j = 0; j < result.size; j++) {
				tmp[j] = result.vector[j];
			}
			delete [] result.vector;
			result.vector = new char[++result.size];
			result.vector[0] = 1;
			int k = 1;
			for (int j = 0; j < result.size; j++) {
				result.vector[k++] = tmp[j];
			}
		}
	}
	return result;
}

BinVect& BinVect :: operator += (BinVect &v) {
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









#endif
