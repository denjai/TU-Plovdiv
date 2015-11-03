//---------------------------------------------------------------------------
#pragma hdrstop
#include "bel.h"
#include "fib.h"
#include <string.h>
#define EOT -1
#define BOT -1
#pragma package(smart_init)

int bel::append(char * name, char* fam, unsigned long tel)
{
	if (tableend >= zapisi)
	{
		int k = fnumber.set(zapisi);
		belrow *p = new belrow[k];
		for (int i = 0; i < tableend; i++)
		{
			strcpy(p[i].name, table[i].name);
			strcpy(p[i].fam, table[i].fam);
			p[i].tel = table[i].tel;
		}
		delete[] table;
		table = p;
		zapisi = k;
	}
	strcpy(table[tableend].name, name);
	strcpy(table[tableend].fam, fam);
	table[tableend].tel = tel;
	tableend++;
	return 1;
}

int bel::append(belrow * arow)
{

	if ((tableend) >= zapisi)
	{
		int k = fnumber.set(zapisi);
		belrow *p = new belrow[k];
		for (int i = 0; i < tableend; i++)
		{
			strcpy(p[i].name, table[i].name);
			strcpy(p[i].fam, table[i].fam);
			p[i].tel = table[i].tel;
		}
		delete[] table;
		table = p;
		zapisi = k;
	}
	memcpy(&table[tableend], arow, sizeof(belrow));
	tableend++;
	return 1;
}

belrow * bel::findrowbyname(char *name)
{
	for (int i = 0; i < tableend; i++)
		if (!strcmp(table[i].name, name))
			return &table[i];
	return NULL;
}

void bel::first()
{
	curentrecord = 0;
}

int bel::next() {
	if (curentrecord == (tableend - 1))
		return EOT;
	else ++curentrecord;
	return curentrecord;
}

int bel::prev()
{
	if (curentrecord == 0)
		return BOT;
	else return --curentrecord;
}

void bel::last()
{
	curentrecord = tableend - 1;
}

belrow *bel::get()
{
	if (curentrecord == -1)
		return NULL;
	return &table[curentrecord];
}

