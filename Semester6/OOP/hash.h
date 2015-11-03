#ifndef hash
#define hash
#include <string.h>

struct tb
{
	char bg[20];
	char en[20];
};

class THashTable
{
	tb table[128];
	int count;
public:
	THashTable(void)
	{
		for (int i = 0; i < 128; i++)
		{
			table[i].bg[0] = '\0';
			table[i].en[0] = '\0';
		}
	}

	int search(char *bg, char *en, int &k);
	int add(char *bg, char *en);
	int remove(char *bg);
	void print(void);
	int hashfunc(char *bg);
};
#endif
