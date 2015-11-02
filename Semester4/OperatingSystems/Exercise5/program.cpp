#include <stdio.h>
#include <windows.h>
#include <conio.h>

DWORD tid = 0;
int broi = 0;
int c1, c2;

HANDLE h;
HANDLE mut;

struct threadinfo
{
	HANDLE handle;
	DWORD id;
};

DWORD WINAPI func(void *p)
{
	int k = 0, l = 0;
	struct threadinfo *t;
	t = (struct threadinfo*)p;

	while (k < c1)
	{
		WaitForSingleObject(mut, INFINITE);
		tid = t->id;
		while (l < c2)
			l++;
		if (tid != t->id)
			broi++;
		l = 0;
		k++;
		ReleaseMutex(mut);
	}
	printf("\n thread %d terminated", ((struct threadinfo *)p)->id);
	return 0;
}


int main()
{
	int n, i, j;
	struct threadinfo *t;

	printf("vuvedete broq nishki:");
	scanf("%d", &n);
	t = (struct threadinfo*)malloc(n*sizeof(struct threadinfo));
	printf("\ncikul 1: ");
	scanf("%d", &c1);
	printf("\ncikul2: ");
	scanf("%d", &c2);
	mut = CreateMutex(NULL, FALSE, NULL);

	for (i = 0; i < n; i++)
	{
		t[i].handle = CreateThread(NULL, 0, func, t + i, CREATE_SUSPENDED, &(t[i].id));
	}

	for (i = 0; i < n; i++)
	{
		ResumeThread(t[i].handle);
	}


	for (i = 0; i < n; i++)
	{
		DWORD ret;
		h = t[i].handle;
		ret = WaitForSingleObject(h, INFINITE);
	}

	for (i = 0; i < n; i++)
	{
		CloseHandle(t[i].handle);
	}

	printf("\nbroi nesinhronizirani dostupi: %d", broi);

	getch();
	return 0;
}
