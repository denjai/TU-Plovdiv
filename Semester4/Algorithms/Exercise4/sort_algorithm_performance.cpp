#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define N 5000
typedef int t_element; 
void sort(t_element A[],int min,int max,int n){
	int i,j,k;
t_element P[N];
for(i=min;i<=max;i++)
  P[i]=0;
for(j=0;j<n;j++) P[A[j]]++;
for(j=0,i=min;i<=max;i++)
  for(k=0;k<P[i];k++)
	  A[j++]=i;
}
void sort_vmykvane(int n, t_element A[])
{
int i,j;
t_element p;
for(i=1; i<n; i++)
{
p=A[i];
j=i-1;
while((A[j]>p)&&(j>=0))
{
A[j+1]=A[j];
j--;
}
A[j+1]=p;
}
}
int DvoichnoTyrsene(int l, int r, t_element x, t_element A[])
{
int m;
while(l<=r)
{
m=(l+r)/2;
if (x<A[m])
r=m-1;
else
l=m+1;
}
return l;
}
void sort_vmykvane_d(int n, t_element A[])
{
int i,j, j1;
t_element p;
for(i=1; i<n; i++)
{
p=A[i];
j1=DvoichnoTyrsene(0,i-1,p,A);
for(j=i-1; j>=j1; j--)
A[j+1]=A[j];
A[j1]=p;
}
}
void razmiana(t_element & x, t_element & y)
{
t_element p;
p=x;
x=y;
y=p;
}
void mehurche(int n, t_element A[])
{
int j, i;
for(i=0; i<n-1; i++)
{
for(j=n-1; j>=i+1; j--)
{
if (A[j]<A[j-1])
razmiana(A[j],A[j-1]);
}
}
}
void Shellsort(t_element A[], int n)
{
int delta, j, i;
t_element R;
bool flag;
delta = n/2;
while(delta>0)
{
for(i=delta; i<n; i++)
{
R=A[i];
j=i;
flag=true;
while((j-delta>=0)&&(flag))
{
if (R<A[j-delta])
{
A[j]=A[j-delta];
j=j-delta;
}
else
{
flag=false;
}
}
A[j]=R;
}
delta=delta/2;
}
}
void qs(t_element A[],int start,int stop)
{int i=start, j=stop;
t_element m,k;
m=A[(start+stop)/2];
do{
	while(A[i]<m)i++;
	while(A[j]>m)j--;
	if(i<=j)
	{k=A[i];
	A[i]=A[j];
	A[j]=k;
	i++;
	j--;
	}
}
while(i<=j);
if(j>start)
 qs(A,start,j);
 if(i<stop)
	 qs(A,i,stop);
}

int main()
{t_element A[N];
t_element n,m=0,i,q,r,s;


for(i=0;i<N;i++)
	A[i]=rand();
r=GetTickCount();
mehurche(N,A);
s=GetTickCount();
q=s-r;
printf("\nmetod na mehurcheto; %d",q);

for(i=0;i<N;i++)
	A[i]=rand();
r=GetTickCount();
qs(A,0,N-1);
s=GetTickCount();
q=s-r;
printf("\nquicksort; %d",q);

for(i=0;i<N;i++)
	A[i]=rand()%N;
r=GetTickCount();
sort(A,0,N,N);
s=GetTickCount();
q=s-r;
printf("\ncifrovo sortirane; %d",q);

for(i=0;i<N;i++)
	A[i]=rand();
r=GetTickCount();
Shellsort(A,N);
s=GetTickCount();
q=s-r;
printf("\nshell; %d",q);

for(i=0;i<N;i++)
	A[i]=rand();
r=GetTickCount();
sort_vmykvane(N,A);
s=GetTickCount();
q=s-r;
printf("\nvmukvane; %d",q);

for(i=0;i<N;i++)
	A[i]=rand();
r=GetTickCount();
sort_vmykvane_d(N,A);
s=GetTickCount();
q=s-r;
printf("\ndvoichno vmukvane; %d",q);






getch();
return 0;
}