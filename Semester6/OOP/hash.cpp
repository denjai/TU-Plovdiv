#pragma hdrstop
#include "hash.h"
#include <string.h>
#include <stdio.h>
#pragma package(smart_init)

int THashTable::hashfunc(char *bg)
{
	int sum = 0;
	for (int i = 0; bg[i]; i++)
		sum += bg[i];
	sum = sum & 127;
	return sum;
}

int THashTable::search(char *bg, char *en, int &k)
{
	int flag = 1;
	int n = hashfunc(bg);
	int p = n;
	while (flag) {
		if (!strcmp(table[n].bg, bg))
		{
			k = n;
			en = table[n].en;
			return 0;
		}
		else if (strlen(table[n].bg) == 0)
		{
			k = n;
			return 1;
		}
		else n++;
		if (flag == 2 && p == n)
			return -1;
		if (n == 127) {
			n = 0;
			flag = 2;
		}
	}
}
int THashTable::add(char *bg, char *en)
{
	int k;
	int p = search(bg, en, k);
	if (p == 1) {
		strcpy(table[k].bg, bg);
		strcpy(table[k].en, en);
	}
	return p;
}
int THashTable::remove(char *bg)
{
	int k;
	int p = search(bg, NULL, k);
	if (p == 0) {
		table[k].bg[0] = '\0';
		table[k].en[0] = '\0';
		return 0;
	}
	return 1;
}

void THashTable::print(void)
{
	for (int i = 0; i < 128; i++)
	{
		if (table[i].bg[0] != '\0')
		{
			fputs(table[i].bg, stdout);
			printf("\t");
			fputs(table[i].en, stdout);
			printf("\n");
		}
	}
}
