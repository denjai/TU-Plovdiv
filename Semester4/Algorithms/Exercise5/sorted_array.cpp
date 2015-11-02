#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int BinSearch(int l, int r, float x, float A[])
{
	int m;
	while (l <= r) {
		m = (l + r) / 2;
		if (x < A[m])
			r = m - 1;
		else
			if (x > A[m])
				l = m + 1;
			else
				return m;
	}
	return -1;
}

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
int main() {
	float a[50], x, k;
	int i, n;

	do {
		printf("Vavedete broi elementi: ");
		scanf("%d", &n);
	} while (n < 0 || n>50);

	printf("Vavedete elementi za masiva\n");

	for (i = 0; i < n; i++) {
		scanf("%f", &k);
		a[i] = k;
	}

	qs(a, 0, n);

	printf("vavedete 4islo za tarsene: \n");
	scanf("%f", &x);

	k = BinSearch(0, n, x, a);

	if (k != -1)
		printf("indexa e %.0f\n", k - 1);
	else
		printf("chisloto ne e namereno");

	getch();
	return 0;
}