//---------------------------------------------------------------------------
#ifndef belH
#define belH
#include "fib.h"
//---------------------------------------------------------------------------
struct belrow
{
	char name[12];
	char fam[15];
	unsigned long tel;
};

class bel
{
	belrow *table;
	int tableend;
	int curentrecord;
	int zapisi;
	TFibonacci fnumber;
public:
	bel(int br)
	{
		tableend = 0;
		zapisi = fnumber.set(br);
		table = new belrow[zapisi];
	}
	~bel(void) { delete table; }
	int append(char * name, char* fam, unsigned long tel);
	int append(belrow * arow);
	belrow *findrowbyname(char * name);

	void first();
	int next();
	int prev();
	void last();
	belrow *get();

};
#endif
