#include <stdio.h>
#include <conio.h>
#include <windows.h>
struct person
{
	int id;
	char fname[20];
	char lname[20];
};

int main() {
	LARGE_INTEGER b, e;
	int n = 1000, id, i;
	long long le, lb, result;
	struct person *p;

	p = (struct person*)malloc(sizeof(struct person)*n);
	QueryPerformanceCounter(&b);

	for (i = 0; i < n; i++)
	{
		id = p[i].id;  //chetene
	}
	//p[i].id=i //zapis

	QueryPerformanceCounter(&e);
	lb = b.LowPart + (((long long)b.HighPart) << 32); // <<32 otmestvane na 32 bita
	le = e.LowPart + (((long long)e.HighPart) << 32);

	result = le - lb;
	printf("performance: %ld\n", result);

	getch();
	free(p);
	return 1;
}
