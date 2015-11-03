#include <stdio.h>
#include <conio.h>
#include "table.h"
#include "TDihot.h"
#include "tree.h"
#include "hash.h"

int main()
{
	FILE * pr, *pbg, *pen;
	char bgword[20];
	char enword[20];
	int s;
	//Ttable obj;
	//TDihotTable obj;
	//TBinTree obj;
	THashTable obj;

	pr = fopen("data.txt", "r");
	if (!pr)
	{
		printf("file cannnot be opened-1");
		getch();
		return 0;
	}
	pbg = fopen("data_bg.txt", "r");
	if (!pbg)
	{
		printf("file cannnot be opened-2");
		getch();
		return 0;
	}

	pen = fopen("data_en.txt", "a");
	if (!pen)
	{
		printf("file cannnot be opened-3");
		getch();
		return 0;
	}

	while (!feof(pr))
	{
		fscanf(pr, "%s", bgword);
		fscanf(pr, "%s", enword);
		obj.add(bgword, enword);
	}
	obj.print();

	while (!feof(pbg))
	{
		fscanf(pbg, "%s", bgword);
		int k = obj.search(bgword, enword, s);
		if (k != -1)
			fprintf(pen, "%s\n", enword);

	}

	_getch();
	return 0;
}
