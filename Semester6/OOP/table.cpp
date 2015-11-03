#include <stdio.h>
#include "table.h"
#include <string.h>

int Ttable::search(char* bg, char* en)
{
	for (int i = 0; i < count; i++)
		if (!strcmp(bg, tb[i].wordbg))
		{
			if (en)
				strcpy(en, tb[i].worden);
			return i;
		}
	return -1;

}

int Ttable::add(char *bg, char *en) {
	if (count < 50 && (search(bg, NULL) == -1))
	{
		strcpy(tb[count].wordbg, bg);
		strcpy(tb[count].worden, en);
		count++;
		return 1;
	}
	return -1;
}

int Ttable::remove(char* bg)
{
	int p = search(bg, NULL);
	if (p != -1)
	{
		strcpy(tb[p].wordbg, tb[count - 1].wordbg);
		strcpy(tb[p].worden, tb[count - 1].worden);
		count--;
		return 1;
	}
	return -1;
}

void Ttable::print()
{
	for (int i = 0; i < count; i++)
	{
		fputs(tb[i].wordbg, stdout);
		printf("\t");
		fputs(tb[i].worden, stdout);
		printf("\n");
	}
}
