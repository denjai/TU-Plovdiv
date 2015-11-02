#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char **a, **b, **c;
	int i, j, k, p, q, r, l, s, t;
	s = atoi(argv[1]);//maksimalna duljina na simvolnite nizove
	q = atoi(argv[2]);//broi elementi na mnojestvo A
	r = atoi(argv[3]);//broi elementi na mnojestwo B
	a = (char**)malloc(q*sizeof(char*));
	for (i = 0; i < q; i++)
		a[i] = (char*)malloc((s + 1)*sizeof(char));
	b = (char**)malloc(r*sizeof(char*));
	for (i = 0; i < r; i++)
		b[i] = (char*)malloc((s + 1)*sizeof(char));
	c = (char**)malloc((r*q)*sizeof(char*));
	for (i = 0; i < (r*q); i++)
		c[i] = (char*)malloc((2 * s + 1)*sizeof(char));
	for (i = 0; i < q; i++) {
		printf("vuvedete element(string) %d za mnojestvo a:", i);
		fflush(stdin);
		fgets(a[i], s, stdin);

	}
	for (i = 0; i < q; i++)
		puts(a[i]);
	for (i = 0; i < r; i++) {
		printf("vuvedete element(string) %d za mnojestvo b:", i);
		fflush(stdin);
		fgets(b[i], s, stdin);
		fflush(stdin);

	}
	for (i = 0; i < r; i++)
		puts(b[i]);
	printf("\nIzberete operaciq:\n 1-obedinenie,\n 2-sechenie,\n 3-razlika,\n 4-dekartovo proizvedenie,\n 5-exit\n");
	scanf_s("%d", &t);
	if (t == 1) {                          //obedinenie
		for (i = 0; i < q; i++)
			strcpy(c[i], a[i]);
		for (i = 0, p = 0, j = 0, k = 0; j < r; i++) {
			if (!strcmp(a[i], b[j]))
				p++;
			if (i == q - 1) {
				if (p == 0) {
					strcpy(c[q + k], b[j]);
					k++;
				}
				i = 0;
				j++;
			}
		}
		for (i = 0; i < q + k; i++)
			puts(c[i]);
	}
	if (t == 2) {                      //sechenie
		for (i = 0, p = 0, j = 0, k = 0; j < r; i++) {
			if (!strcmp(a[i], b[j]))
				p++;
			if (i == q - 1) {
				if (p != 0) {
					strcpy(c[k], b[j]);
					k++;
				}
				i = 0;
				j++;
			}
		}
		for (i = 0; i < k; i++)
			puts(c[i]);

	}
	if (t == 3) {                      //razlika
		for (i = 0, j = 0, k = 0; j < r; i++) {
			if (strcmp(a[i], b[j])) {
				strcpy(c[k], a[i]);
				k++;
			}
			if (i == q - 1) {
				i = 0;
				j++;
			}
		}
		for (i = 0; i < k; i++)
			puts(c[i]);

	}
	if (t == 4) {                      //dekartovo proizvedenie
		for (l = 0; l < q; l++)
			strcpy(c[l], a[l]);

		for (i = 0, p = 0, j = 0, k = 1; j < r + 1; i++) {
			strcat(c[i], b[j]);
			if (i == k*q - 1) {
				for (l = k*q; l < (k + 1)*q; l++, p++)
					strcpy(c[l], a[p]);
				j++;
				k++;
			}
		}
		for (i = 0; i < q*r; i++)
		{
			puts(c[i]);
		}
	}
	getch();
	for (i = 0; i < q; i++)
		free(a[i]);
	free(a);
	for (i = 0; i < r; i++)
		free(b[i]);
	free(b);
	for (i = 0; i < (r*q); i++)
		free(c[i]);
	free(c);

	return 0;

}