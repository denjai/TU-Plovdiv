#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define N 5

int used[N];

int a[N][N] = { 0,1,1,1,0,1,0,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,0,0,0 };

void DFS(int v) {
	int i;
	used[v] = 1;
	printf("%d\n", v + 1);
	for (i = 0; i < N; i++)
	{
		if (a[v][i] && !used[i])
		{
			DFS(i);
		}
	}
}
int main() {
	int i, x;
	for (i = 0; i < N; i++)
	{
		used[i] = 0;
	}

	printf("vuvedete vruh:");
	scanf("%d", &x);

	DFS(x - 1);

	getch();
	return 0;
}
