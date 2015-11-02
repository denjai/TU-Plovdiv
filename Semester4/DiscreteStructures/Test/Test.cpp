#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int fact(int n) {
	int i = 1, r = 1;
	while (i <= n) {
		r = r*i;
		i++;
	}
	return r;
}

void qs(int A[], int start, int stop)
{
	int i = start, j = stop;
	int m, k;
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
void leksiko(int a[], int n) {
	int k, i, q, r, l, t;
	for (i = 0, k = a[0]; i < n; i++) {
		if (k < a[i])
			continue;
		else {
			k = a[i];
			l = i;
		}
	}
	for (i = l + 2, q = a[l + 1]; i < n; i++) {
		if (q < a[i])
			continue;
		else {
			q = a[i];
			r = i;
		}
	}
	t = a[l];
	a[l] = a[r];
	a[r] = t;
	qs(a, l + 1, n - 1);
	for (i = 0; i < n; i++)
		printf("%d", a[i]);
}
int main(int argc, char *argv[]) {
	int m, k, n = 4, **b, mb = 327, me = 332, i, z, j, *s, l, h;
	char *q, **a;


	//n=strlen(argv[1]);
	//mb=atoi(argv[1]);
	//me=atoi(argv[2]);
	s = (int *)malloc(sizeof(int)*n);
	q = (char *)malloc(sizeof(char)*n);
	m = me - mb + 1;
	a = (char **)malloc(m*sizeof(char*));
	for (i = 0; i < m; i++)
		a[i] = (char*)malloc(n*sizeof(char));
	b = (int**)malloc(m*sizeof(int*));
	for (i = 0; i < m; i++)
		b[i] = (int*)malloc(n*sizeof(int));
	//q=argv[1]
	for (i = 0; i < m; i++) {
		strcpy(a[i], q);
		mb++;
		sprintf(q, "%d", mb);
	}
	for (i = 0; i < m; i++)
		for (j = 0; j < n - 1; j++)
			b[i][j] = atoi(a[i][j]);

	for (i = 0; i < m; i++) {
		for (k = 0; k < n - 1; k++)
			s[k] = b[i][k];
		for (k = 0; k < n - 1; k++)
			printf("%d\n\n", a[i][k]);
		qs(s, 0, n - 1);
		for (j = 0; j < fact(n - 1) - 1; j++) {
			leksiko(s, n - 1);
			for (l = 0; l < n - 1; l++) {
				if (s[l] < b[i][l])
					for (h = 0; h < n - 1; h++) {
						printf("%d", s[h]);
						printf("\n");
					}
				else continue;
			}
		}
	}

	system("PAUSE");
	return 0;
}