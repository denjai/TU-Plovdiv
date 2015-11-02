```cpp
// programa 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
int func1(int m, int n)
{
	if (m == 0)
		return n;
	while (n != 0)
	{
		if (m > n)
			m = m - n;
		else
			n = n - m;
	}
	return m;
}
int func2(int p, int k)
{
	int h;
	while (k != 0)
	{
		h = k;
		k = p%k;
		p = h;
	}
	return p;
}

void func3()
{
	int m, n, q, r, t, v;
	printf("vyvedete chislitel:");
	scanf("%d", &m);
	printf("vyvededte znamenatel:");
	scanf("%d", &n);
	t = m;
	v = n;
	q = func1(m, n);
	r = func2(m, n);
	printf("nai-golemiq delitel e: %d", q);
	printf("nai-golemiq delitel e: %d", r);
	t = t / q;
	v = v / r;
	printf("tvoqta sykratena drob e s chislitel:\t %d i znamenatel\t %d", t, v);
}
int main() {
	func3();
	system("Pause");
	return 0;
}
```
