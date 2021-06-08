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

BinVect& BinVect :: operator + (BinVect &v) {
	int i = 0;
	char rank = 0;
	//size > v.size ? BinVect
	BinVect& res_vect (*this);
	char tmp2[size];
	for (int i = 0; i < v.size; ++i) {
			tmp2[i] = v.vector[i];
	}
	if (size > v.size) {
		int j = 0;
		for (i = 0; i < size; ++i) {
			if (i < (size - v.size)) {
				tmp2[i] = 0;
			} else {
				tmp2[i] = v.vector[j];
				++j;
			}
		}
	}
	
	for (i = 0; i < size; ++i) {
		res_vect.vector[i] += tmp2[i] + rank;
		rank = 0;
		if (res_vect.vector[i] > 1) {
			res_vect.vector[i] %= 2;
			rank++;
		}
		if ((i == 0) && (rank)) {
			char tmp[size];
			int j = 0;
			for (j = 0; j < size; j++) {
				tmp[j] = res_vect.vector[j];
			}
			delete [] res_vect.vector;
			res_vect.vector = new char[size + 1];
			res_vect.vector[0] = 1;
			int k = 1;
			for (j = 0; j < size; j++) {
				res_vect.vector[k++] = tmp[j];
			}
		}
	}
	return res_vect;
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
