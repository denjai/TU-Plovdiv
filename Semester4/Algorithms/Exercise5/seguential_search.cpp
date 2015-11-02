#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main() {
	float a[10] = { 12, 4.7, -7, 16, 5 };
	int i, n = 6, x;

	printf("vavedete 4islo za tarsene  ");
	scanf("%d", &x);

	for (i = 0; i < n; i++)
		if (x == a[i]) {
			printf("chisloto e: %d\n", x);
			break;
		}

	if (i == n)
		printf("chisloto ne e namereno");

	getch();
	return 0;
}
