#pragma hdrstop
#include "TDihot.h"
#include <string.h>
#include <stdio.h>
#pragma package(smart_init)

int TDihotTable::search(char *bg, char *en, int &k)
{
	int start = 0, end = count - 1, m;
	m = (start + end) / 2;
	while (start < end)
	{
		if (!strcmp(tb[m].wordbg, bg)) return m;
		else if (strcmp(tb[m].wordbg, bg) < 0)
		{
			start = m + 1;
			m = (start + end) / 2;
		}
		else {
			end = m - 1;
			m = (start + end) / 2;
		}
	}
	k = m;
	return -1;
}
int TDihotTable::add(char *bg, char *en)
{
	int k, i;
	if (count >= 50) return 0;
	if (count == 0) {
		strcpy(tb[0].wordbg, bg);
		strcpy(tb[0].worden, en);
		count++;
	}
	if (count == 1)
	{
		if (!strcmp(tb[0].wordbg, bg)) return -1;
		else if (strcmp(tb[0].wordbg, bg) < 0)
		{
			strcpy(tb[1].wordbg, bg);
			strcpy(tb[1].worden, en);
			count++;
		}
		else
		{
			strcpy(tb[1].wordbg, tb[0].wordbg);
			strcpy(tb[1].worden, tb[0].worden);
			strcpy(tb[0].wordbg, bg);
			strcpy(tb[0].worden, en);
			count++;
		}
	}
	else
	{
		if (search(bg, en, k) != -1) return -1;
		else
		{
			char tmpbg[10], tmpen[10], tmpbg1[10], tmpen1[10];
			strcpy(tmpbg, tb[k].wordbg);
			strcpy(tmpen, tb[k].worden);
			strcpy(tb[k].wordbg, bg);
			strcpy(tb[k].worden, en);
			count++;
			int l = 3;
			for (i = k + 1; i < count - 1; i++)
			{
				if (l % 2)
				{
					strcpy(tmpbg1, tb[i].wordbg);
					strcpy(tmpen1, tb[i].worden);
					strcpy(tb[i].wordbg, tmpbg);
					strcpy(tb[i].worden, tmpen);
					l++;
				}
				else
				{
					strcpy(tmpbg, tb[i].wordbg);
					strcpy(tmpen, tb[i].worden);
					strcpy(tb[i].wordbg, tmpbg1);
					strcpy(tb[i].worden, tmpen1);
					l++;
				}
			}
			if (l % 2)
			{
				strcpy(tb[i].wordbg, tmpbg);
				strcpy(tb[i].worden, tmpen);
			}
			else
			{
				strcpy(tb[i].wordbg, tmpbg1);
				strcpy(tb[i].worden, tmpen1);
			}
		}
	}
	return 1;
}
int TDihotTable::remove(char* bg)
{
	int k;
	int p = search(bg, NULL, k);
	if (p != -1)
	{
		for (int i = p; i < count - 1; i++)
		{
			strcpy(tb[i].wordbg, tb[i + 1].wordbg);
			strcpy(tb[i].worden, tb[i + 1].worden);
		}

		count--;
		return 1;
	}
	return -1;
}

void TDihotTable::print()
{
	for (int i = 0; i < count; i++)
	{
		fputs(tb[i].wordbg, stdout);
		printf("\t");
		fputs(tb[i].worden, stdout);
		printf("\n");
	}
}
