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
	void output (void) const;
	BinVect (const BinVect &v);
	BinVect& operator = (const BinVect &v);
	BinVect operator + (const BinVect &v) const;
	BinVect operator - (const BinVect &v) const;
	BinVect operator -= (const BinVect &v);
	BinVect operator += (const BinVect &v);
	bool operator > (const BinVect &v) const; 
	bool operator == (const BinVect &v) const;
	bool operator != (const BinVect &v) const;
	bool operator < (const BinVect &v) const;
	bool operator >= (const BinVect &v) const;
	bool operator <= (const BinVect &v) const;
	BinVect operator << (const int position);
	BinVect operator >> (const int position);
	char get (int index, int &error) const;
	void set (int index, char value, int &error);
	int max_sequence (void) const;
};
#endif
