#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct student
{
	int fnum;
	char fname[20];
	char lname[20];
};

int main(int argc, char* argv[])
{
	int x, i, j, num, k;
	struct student* A;

	x = atoi(argv[1]);
	A = (struct student*)malloc(x*sizeof(struct student));

	if (A == NULL) return(1);

	for (i = 0; i < x; i++)
	{
		printf("vuvedete  fakulteten nomer na student: ");
		scanf("%d", &A[i].fnum);
		fflush(stdin);
		printf("\n vuvedete  lichno ime na student:");
		gets(A[i].lname);
		printf("\n vuvedete  familno ime na student:");
		gets(A[i].fname);
	}

	for (i = 0; i < x; i++)
	{
		printf("fnum:%d\t", A[i].fnum);

		printf("\ime:");
		puts(A[i].lname);

		printf("\familiq:");
		puts(A[i].fname);
		printf("\n\n\n");
	}
	do {
		printf("vuvedete fakulteten nomer za tursene:");
		scanf("%d", &num);
		for (i = 0; i < x; i++)
			if (num == A[i].fnum)
			{
				printf("fnum: %d\t", A[i].fnum);

				printf("\nime:");
				puts(A[i].lname);

				printf("\nfamiliq:");
				puts(A[i].fname);
			}
		printf("vuvedete 1 za izhod ili 2 za povtorno tursene\t");
		scanf("%d", &k);
	} while (k == 2);

	getch();
	return 0;
}
