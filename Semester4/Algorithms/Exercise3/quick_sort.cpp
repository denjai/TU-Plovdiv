#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void qs(float A[], int start, int stop)
{
	int i = start, j = stop;
	float m, k;
	m = A[(start + stop) / 2];

	do {
		while (A[i] < m)i++;
		while (A[j] > m)j--;
		if (i <= j)
		{
			k = A[i];
			A[i] = A[j];
			A[j] = k;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > start)
		qs(A, start, j);
	if (i < stop)
		qs(A, i, stop);
}
int main()
{
	float A[100];
	int n, m = 0, i;

	printf("vyvedete razmer na masiva:\t");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("vyvedete element na masiva A[%d]", i);
		scanf("%f", &A[i]);
	}

	qs(A, m, n - 1);

	for (i = 0; i < n; i++)
		printf("A[%d]=%f\n", i, A[i]);

	system("pause");
	return 0;
}
