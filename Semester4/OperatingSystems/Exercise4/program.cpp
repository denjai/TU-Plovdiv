#include <stdio.h>
#include <windows.h>
#include <conio.h>

struct threadinfo
{
	HANDLE handle;
	DWORD id;
};

DWORD WINAPI func(void *p) {
	int j;
	for (j = 0; j < 500; j++);
	printf("\nthread %d terminated", (((threadinfo*)p)->id));
	return (((threadinfo*)p)->id);
}

int  main()
{
	struct threadinfo *t;
	int n, i, j;
	printf("vuvedete broq nishki:");
	scanf("%d", &n);
	t = (struct threadinfo*)malloc(n*sizeof(struct threadinfo));

	for (i = 0; i < n; i++)
	{
		t[i].handle = CreateThread(NULL, 0, func, t + i, 0, &(t[i].id));
	}
	printf("\nmain thread terminated");

	getch();
	return 0;
}
