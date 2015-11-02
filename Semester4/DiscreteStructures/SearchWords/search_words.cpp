#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char a[1000];
	char b[100][20];
	int K, i, k, j, rp = 0, N;
	printf("vuvedete izrechenie:");
	fgets(a, 1000, stdin);
	k = 0;
	j = 0;
	for (i = 0; i < 1000; i++) {
		if ((a[i] >= 0x41 && a[i] <= 0x5A) || (a[i] >= 0x61 && a[i] <= 0x7A)) {
			b[k][j] = a[i];
			j++;
			rp = 0;
		}
		else {
			b[k][j] = 0;
			if (!rp) {
				k++;
				j = 0;
				rp = 1;
			}
		}
	}
	N = k;
		for (i = 0; i < N; i++)
			for (j = 0; b[i][j] != 0; j++)
				b[i][j] = b[i][j] | 0x80;

	getch();
	return 0;
}


