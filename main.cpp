#include <stdio.h>
#include "BinVect.h"
/*
	Создайте класс BinVect (двоичный вектор) с операциями +, +=, -, -=, =, ==, !=, >, <, >=, <=, << (int) (сдвиг влево), >> (int) (сдвиг вправо).
*/
int main () {
	BinVect a (5);
	while (a.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	BinVect b (5);
	while (b.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	BinVect c = a + b;
	c.output ();
	return 0;
}
