#include <stdio.h>
#include "BinVect.h"
/*
	Создайте класс BinVect (двоичный вектор) с операциями +, +=, -, -=, =, ==, !=, >, <, >=, <=, << (int) (сдвиг влево), >> (int) (сдвиг вправо).
	Доп.: Реализовать метод, определяющий длину максимальной последовательности единиц в векторе.
*/
int main () {
	/*printf ("Addition:\n");
	BinVect a1 (4);
	while (a1.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	BinVect b1 (3);
	while (b1.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	BinVect res1 = a1 + b1;
	res1.output ();
	a1 += b1;
	a1.output ();
	
	printf ("Subtraction:\n");
	BinVect a2 (3);
	while (a2.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	BinVect b2 (2);
	while (b2.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	BinVect res2 = a2 - b2;
	res2.output ();
	a2 -= b2;
	a2.output ();
	
	printf ("Compare:\n");
	BinVect a3 (3);
	while (a3.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	BinVect b3 (3);
	while (b3.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	if (a3 > b3) {
		printf ("Vector 1 more than Vector 2\n");
	} else {
		if (a3 == b3) {
			printf ("Vectors are equal\n");
		} else {
			printf ("Vector 2 more than Vector 1\n");
		}
	}
	if (a3 != b3) {
		printf ("Vectors are not equal\n");
	}
	if (a3 >= b3) {
		printf ("Vector 1 more or equal than Vector 2\n");
	}
	if (a3 <= b3) {
		printf ("Vector 2 more or equal than Vector 1\n");
	}
	
	printf ("Sdvig:\n");
	BinVect a4 (3);
	while (a4.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	BinVect b4 (3);
	while (b4.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	a4 << 2;
	b4 >> 2;
	a4.output ();
	b4.output ();*/
	BinVect a5 (15);
	while (a5.input ()) {
		printf ("ERROR! COMPONENTS OF THE BINARY VECTOR MUST BE 1 OR 0\n");
	}
	printf ("Max sequence of 1 is : %d\n", a5.max_sequence ());
	return 0;
}
