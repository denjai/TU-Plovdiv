#pragma hdrstop
#include "tree.h"
#include <string.h>
#include <stdio.h>
#pragma package(smart_init)

int TBinTree::search(char* bg, char* en, int &n)
{
	for (int i = 0; ;)
	{
		if (strcmp(tb[i].bg, bg) == 0)
		{
			n = i;
			return 1;
		}
		if (strcmp(tb[i].bg, bg) > 0)
		{
			if (tb[i].l == -1)
			{
				n = i;
				return -1;
			}
			else {
				i = tb[i].l;
			}
		}
		if (strcmp(tb[i].bg, bg) < 0)
		{
			if (tb[i].r == -1) {
				n = i;
				return -2;
			}
			else {
				i = tb[i].r;
			}
		}
	}
}
int TBinTree::add(char *bg, char *en)
{
	int  n, k;

	if (tableend > 50) return 0;
	if (tableend == 0) {
		strcpy(tb[tableend].bg, bg);
		strcpy(tb[tableend].en, en);
		tb[0].l = tb[0].r = -1;
		tableend++;
		return 1;
	}
	else
	{
		k = search(bg, en, n);
		if (k < 0)
		{
			strcpy(tb[tableend].bg, bg);
			strcpy(tb[tableend].en, en);
			tb[tableend].l = tb[tableend].r = -1;
			if (k == -1)
				tb[n].l = tableend;
			if (k == -2)
				tb[n].r = tableend;
			tableend++;
			return 1;
		}
	}
	return 2;
}


void TBinTree::print()
{
	for (int i = 0; i < tableend; i++)
	{
		fputs(tb[i].bg, stdout);
		printf("\t");
		fputs(tb[i].en, stdout);
		printf("\t %d", tb[i].l);
		printf("\t %d", tb[i].r);
		printf("\n");
	}
}
