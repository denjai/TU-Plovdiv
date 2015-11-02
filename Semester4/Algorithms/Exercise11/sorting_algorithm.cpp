#include <stdio.h>
#include <conio.h>

#define nmax 7
#define t_element  float

void merge(int i1, int i2, int j1, int j2, t_element A[])
{
	t_element T[nmax]; //definira pomoshten massiv T
	int k, n;
	n = j2 - i1 + 1; //namira obshtata dyljina na 2ta podmassiva
	k = i1;

	while ((i1 <= i2) && (j1 <= j2)) //obhojda 2ta podmasiva
	{
		if (A[i1] < A[j1])//proverqva tekushtiq element ot 1viq podmasiv, dali e po malak ot tekushtiq elemnt ot 2riq podmassiv
		{
			T[k] = A[i1]; //v masiva T na poziciq k, zapisva tekushtiq elemnt ot 1viq podmasiv
			i1++;
		}
		else
		{
			T[k] = A[j1]; //v masiva T na poziciq k, zapisva tekushtiq elemnt ot 2riq podmasiv
			j1++;
		}
		k++;
	}

	while (i1 <= i2) //obhojda ne obhodenite elemnti na 1viq podmasiv (2riq podmasiv veche e obhoden)
	{
		T[k] = A[i1];
		i1++;
		k++;
	}

	while (j1 <= j2) //obhojda ne obhodenite elemnti na 2riq podmasiv (1viq podmasiv veche e obhoden celiq)
	{
		T[k] = A[j1];
		j1++;
		k++;
	}

	for (k = 0; k < n; k++) //V masiva A zapisva masiva T
	{
		j1--;
		A[j1] = T[j1];
	}
}

void merge_sort(int i, int j, t_element A[])
{
	int m;
	if (i < j)
	{
		m = (i + j) / 2;  //namira sredata na massiva 
		merge_sort(i, m, A);    //  izvikva merge_sort za 1viq podmassiv; rekursivno 
		merge_sort(m + 1, j, A);   // izvikva merge_sort za 2rata polovina; rekursivno
		merge(i, m, m + 1, j, A);    // izvikva merge s argumenti nachaloto i kraq na 1viq podmasiv, nachaloto i kraq na 2riq podmassiv, masiva s chislata za vavejdane
	}
}

int main() {
	t_element a[nmax];
	int i;

	for (i = 0; i < nmax; i++) {
		printf("Vavedete chislo: ");
		scanf("%f", &a[i]);
	}

	merge_sort(0, 6, a);
	for (i = 0; i < nmax; i++)
	{
		printf("%2.2f  ", a[i]);
	}

	getch();
	return 0;
}

