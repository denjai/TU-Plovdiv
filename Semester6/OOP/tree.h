#ifndef TBinTreeH
#define TBinTreeH

struct Tree 
{
	char bg[10];
	char en[10];
	int l;
	int r;
};

class TBinTree 
{
	Tree tb[50];
	int tableend;
public:
	TBinTree(void) { tableend = 0; }
	int search(char* bg, char* en, int &n);
	int add(char *bg, char *en);
	void print();
};
#endif
