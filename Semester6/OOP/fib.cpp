//---------------------------------------------------------------------------
#pragma hdrstop
#include "fib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
int TFibonacci::set(int g) 
{
	int p = 0;
	while (g >= f2) p = get();
	p = get();
	return p;
}

int TFibonacci::get() 
{
	int x;
	x = f1 + f2;
	f1 = f2;
	f2 = x;

	return f2;
}
