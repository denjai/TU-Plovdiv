#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
	float a[10] = { 12, 4.7, -7, 16, 5 };
	int i = 0, n = 6, x;

	printf("vavedete 4islo za tarsene  ");
	scanf("%d", &x);

	a[n] = x;

	while (x != a[i])
	{
		i++;
	}

	if (i < n)
	{
		printf("indexa e a[%d]", i);
	}
	else
	{
		printf("chisloto ne e namereno");
	}
	getch();
	return 0;
}