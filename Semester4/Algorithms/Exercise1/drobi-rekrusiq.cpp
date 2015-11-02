#include <stdlib.h>
#include <stdio.h>


int func1(int m, int n)
{
	if (n == 0)
		return m;
	else
		func1(n, m%n);
}
int main() {
	int m, n, q;
	printf("vyvedete chislo m:\t");
	scanf("%d", &m);
	printf("vyvedete chislo n:\t");
	scanf("%d", &n);
	q = func1(m, n);
	printf("%d", q);
	system("Pause");
	return 0;
}