// sortirane.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


void sort(int A[], int min, int max, int n)
{
	int i, j, k;
	int P[100];
	for (i = min; i <= max; i++)
		P[i] = 0;
	for (j = 0; j < n; j++) P[A[j]]++;
	for (j = 0, i = min; i <= max; i++)
		for (k = 0; k < P[i]; k++)
			A[j++] = i;
}
int main()
{
	int min, max, n, i, j;
	int A[100];

	do {
		printf("vyvedete razmer do 100:");
		scanf("%d", &n);
	} while (n > 101);

	printf("vyvedete minimalen element:");
	scanf("%d", &min);
	printf("vyvedete maximalen element:");
	scanf("%d", &max);

	for (i = 0; i < n; i++)
	{
		printf("vyvedete element na masiva:");
		scanf("%d", &j);
		if (j >= min && j <= max) A[i] = j;
		else continue;
	}

	sort(A, min, max, n);

	printf("sortiraniqt vi masiv e:");
	for (i = 0; i < n; i++)
		printf("%d\t", A[i]);

	system("pause");
	return 0;
}