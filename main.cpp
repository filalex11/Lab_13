#include <stdio.h>
#include "BinVect.h"
/*
	Создайте класс BinVect (двоичный вектор) с операциями +, +=, -, -=, =, ==, !=, >, <, >=, <=, << (int) (сдвиг влево), >> (int) (сдвиг вправо).
*/
int main () {
	/*BinVect a (2);
	while (a.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	BinVect b (3);
	while (b.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	BinVect c = a + b;
	c.output ();*/
	BinVect a (4);
	while (a.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	/*BinVect b (2);
	while (b.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	if (b <= a) {
		printf ("%d\n", 1);
	} else {
		printf ("%d\n", 0);
	}*/
	a >> 0;
	a.output ();
	return 0;
}
