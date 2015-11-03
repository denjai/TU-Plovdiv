#ifndef TDihotH
#define TDihotH

struct tabl
{
	char wordbg[10];
	char worden[10];
};

class TDihotTable
{
	tabl tb[50];
	int count;
public:
	TDihotTable() { count = 0; }
	int search(char *bg, char *en, int &k);
	int add(char *bg, char *en);
	int remove(char *bg);
	void print();
};
#endif
