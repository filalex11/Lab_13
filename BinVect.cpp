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

void BinVect :: output (void) const {
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

BinVect& BinVect :: operator = (const BinVect &v) {
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

BinVect BinVect :: operator += (const BinVect &v) {
	return *this = *this + v;
}

BinVect BinVect :: operator - (const BinVect &v) const {
	char rank = 1;
	BinVect result (*this);
	if (*this != v) {
		if (*this > v) {
			int j = 0;
			for (int i = 0; i < result.size; ++i) {
				if (i < result.size - v.size) {
					result.vector[i] = 0;
				} else {
					result.vector[i] = v.vector[j];
					++j;
				}
			}
			for (int i = result.size - 1; i >= 0; --i) {
				result.vector[i] += this->vector[i];
				if (result.vector[i] > 1) {
					result.vector[i] %= 2;
				}
			}
			return result;
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
			for (int i = result.size - 1; i >= 0; ++i) {
				result.vector[i] += v.vector[i] + rank;
				rank = 0;
				if (result.vector[i] > 1) {
					result.vector[i] %= 2;
					++rank;
				}
				result.vector[i] = !result.vector[i];
			}
		}	
	}
	for (int i = result.size - 1; i >= 0; --i) {
		result.vector[i] = 0;
	}
	return result;
}

BinVect BinVect :: operator -= (const BinVect &v) {
	return *this = *this - v;
}

bool BinVect :: operator > (const BinVect &v) const {
	if (this->size > v.size) {
		return true;
	}
	if (this->size < v.size) {
		return false;
	}
	int i = 0;
	while ((this->vector[i] == v.vector[i]) && (i < v.size)) {
		++i;
	}
	if (this->vector[i] > v.vector[i]) {
		return true;
	}
	return false;
}

bool BinVect :: operator == (const BinVect &v) const {
	if (this->size != v.size) {
		return false;
	}
	int i = 0;
	while ((this->vector[i] == v.vector[i]) && (i < v.size)) {
		++i;
	}
	if (i == v.size) {
		return true;
	}
	return false;
}

bool BinVect :: operator != (const BinVect &v) const {
	return !(*this == v);
}

bool BinVect :: operator < (const BinVect &v) const {
	return v > *this;
}

bool BinVect :: operator >= (const BinVect &v) const {
	return !(*this < v);
}

bool BinVect :: operator <= (const BinVect &v) const {
	return !(*this > v);
}

BinVect BinVect :: operator << (const int position) {
	int i = 0, j = 0;
	for (i = 0; i < position; ++i) {	
		for (j = 0; j < this->size - 1; ++j) {
			this->vector[j] = this->vector[j + 1];
		}
		this->vector[j] = 0;
	}
	return *this;	
}

BinVect BinVect :: operator >> (const int position) {
	int i = 0, j = 0;
	for (i = 0; i < position; ++i) {	
		for (j = this->size; j > 0; --j) {
			this->vector[j] = this->vector[j - 1];
		}
		this->vector[j] = 0;
	}
	return *this;	
}

char BinVect :: get (int index, int &error) const {
	if ((index < 0) || (index >= size)) {
		error = 1;
		return -1;
	} else {
		return vector[index];
	}
}

void BinVect :: set (int index, char value, int &error) {
	if ((index < 0) || (index >= size)) {
		error = 1;
		return;
	} else {
		vector[index] = value;
	}
}

int BinVect :: max_sequence (void) const {
	int res = 0, count = 0;
	for (int i = 0; i < this->size; ++i) {
		if (this->vector[i] == 1) {
			++count;
		} else {
			if (count > res) {
				res = count;
			}
			count = 0;
		}
	}
	return res;
}
