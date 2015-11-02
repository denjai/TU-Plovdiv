#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int n;
HANDLE h;
HANDLE mr, mw, se, sf;
struct item *arr;
struct threadinfo
{
	HANDLE handle;
	DWORD id;
	int terminate;
};

struct item
{
	int data;
	int empty;
};

DWORD WINAPI write(void *p)
{
	int i;
	struct threadinfo *t;
	t = (struct threadinfo*)p;

	while (!(t->terminate))
	{
		WaitForSingleObject(se, INFINITE);
		WaitForSingleObject(mw, INFINITE);

		for (i = 0; !arr[i].empty; i++);
		arr[i].data = i;
		arr[i].empty = 0;

		printf("\nwrite:A[%d]", i);
		ReleaseMutex(mw);
		ReleaseSemaphore(sf, 1, NULL);
	}
}

DWORD WINAPI read(void *p)
{
	int tmp, i;
	struct threadinfo *t;
	t = (struct threadinfo*)p;

	while (!(t->terminate))
	{
		WaitForSingleObject(sf, INFINITE);
		WaitForSingleObject(mr, INFINITE);
		for (i = 0; arr[i].empty; i++);
		tmp = arr[i].data;
		arr[i].empty = 1;
		printf("\nread:A[%d]", tmp);
		ReleaseMutex(mr);
		ReleaseSemaphore(se, 1, NULL);
	}
}

int main()
{
	int i, j, k, c, p;

	struct threadinfo *pr, *con;

	printf("vuvedete broi elementi na masiva:");
	scanf("%d", &n);
	printf("vuvedete broi consumer nishki:");
	scanf("%d", &c);
	printf("vuvedete broi producer nishki:");
	scanf("%d", &p);

	arr = (struct item*)malloc(sizeof(struct item)*n);
	pr = (struct threadinfo*)malloc(p*sizeof(struct threadinfo));
	con = (struct threadinfo*)malloc(c*sizeof(struct threadinfo));

	for (i = 0; i < n; i++)
		arr[i].empty = 1;
	for (i = 0; i < p; i++)
		pr->terminate = 0;
	for (i = 0; i < c; i++)
		con->terminate = 0;

	mr = CreateMutex(NULL, FALSE, NULL);
	mw = CreateMutex(NULL, FALSE, NULL);
	se = CreateSemaphore(NULL, n, n, NULL);
	sf = CreateSemaphore(NULL, 0, n, NULL);

	for (i = 0; i < c; i++)
	{
		con[i].handle = CreateThread(NULL, 0, read, con + i, CREATE_SUSPENDED, &(con[i].id));
	}
	for (i = 0; i < c; i++)
	{
		ResumeThread(con[i].handle);
	}

	for (i = 0; i < p; i++)
	{
		pr[i].handle = CreateThread(NULL, 0, write, pr + i, CREATE_SUSPENDED, &(pr[i].id));
	}

	for (i = 0; i < p; i++)
	{
		ResumeThread(pr[i].handle);
	}

	Sleep(3000);
	for (i = 0; i < p; i++)
	{
		pr[i].terminate = 1;
	}

	for (i = 0; i < p; i++)
	{
		h = pr[i].handle;
		WaitForSingleObject(h, INFINITE);
	}

	for (i = 0; i < c; i++)
	{
		h = con[i].handle;
		WaitForSingleObject(h, INFINITE);
	}

	free(arr);
	free(pr);
	free(con);
	getch();
	return 0;
}
