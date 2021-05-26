#ifndef BINVECT_H
#define BINVECT_H
class BinVect {
	char *vector;
	int size;
public:	
	BinVect (int s);
	BinVect (void);
	~BinVect (void);
	char input (void);
	void output (void);
	BinVect& operator = (BinVect &v);
	BinVect& operator + (BinVect &v);
	BinVect& operator += (BinVect &v); 
};
#endif
