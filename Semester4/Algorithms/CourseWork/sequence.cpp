#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct st
{
	int start;
	int end;
	int length;
};

int main()
{
	int i, j, k, l, p, s, N;
	int *A;
	struct st *B;

	printf("vuvedete broq na elementite vuv masiva:");
	scanf("%d", &N);
	A = (int *)malloc(sizeof(int)*N);
	B = (struct st*)malloc(sizeof(struct st)*N / 2);

	for (i = 0; i < N; i++)
	{
		printf("A[%d]=", i);
		scanf("%d", &A[i]);
	}

	for (i = 0, k = 0; i < N - 1; i++)
		if (A[i] <= A[i + 1])
		{
			B[k].start = i;
			for (j = i + 1; j < N; j++)
			{
				if (j == N - 2)
				{
					B[k].end = j + 1;
					B[k].length = j - i + 2;
					k++;
					i = j;
					break;
				}

				else
				{
					if (A[j] > A[j + 1])
					{
						B[k].end = j;
						B[k].length = j - i + 1;
						k++;
						i = j;
						break;
					}
				}
			}
		}
	if (k == 0)
	{
		printf("\nnqma namerena nenamalqvashta posledovatelnost ot chisla\n");
	}
	else
	{
		p = B[0].length;
		l = 0;
		for (i = 1; i < k; i++)
		{
			if (p < B[i].length)
			{
				p = B[i].length;
				l = i;
			}
		}
		printf("nai-dulgata posledovatelnost ot nenamalqvashti stoinosti na masiva                                                                                                                          zapochva ot A[%d] i zavurshva do A[%d]. Duljinata i e  %d", B[l].start, B[l].end, p);

		for (i = B[l].start, j = B[l].end; i <= j; i++, j--)
		{
			s = A[i];
			A[i] = A[j];
			A[j] = s;
		}
		printf("\n\nsled zapisvane na posledovatelnostta ot chisla v obraten red,masiva e :");
		for (i = 0; i < N; i++)
		{
			printf("\nA[%d]=%d", i, A[i]);
		}
	}

	getch();
	return 0;
}
