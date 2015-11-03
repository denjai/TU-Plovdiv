-------------------- - table.h------------------------ -
#ifndef tableH
#define tableH

struct dic
{
	char wordbg[10];
	char worden[10];
};

class Ttable
{
	dic tb[50];
	int count;
public:
	Ttable(void) { count = 0; }
	int search(char* bg, char* en);
	int add(char *bg, char *en);
	int remove(char* bg);
	void print();
};

#endif
