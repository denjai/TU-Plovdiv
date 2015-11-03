#include <stdio.h>
#include <string.h>
#include <mem.h>
#include<conio.h>

#define EOT -1
#define BOT -2

struct belrow
{
	char name[12];
	char fam[15];
	unsigned long tel;
};

class bel
{
	belrow table[100];
	int tableend;
	int curentrecord;
public:
	bel(void) { tableend = 0; }
	int append(char * name, char* fam, unsigned long tel);
	int append(belrow * arow);
	belrow *findrowbyname(char * name);

	void first();
	int next();
	int prev();
	void last();
	belrow *get();

};

int bel::append(char * name, char* fam, unsigned long tel) 
{
	if (tableend >= 100) return 0;
	strcpy(table[tableend].name, name);
	strcpy(table[tableend].fam, fam);
	table[tableend].tel = tel;
	tableend++;
	return 1;
}

int bel::append(belrow * arow)
{
	if (tableend >= 100) return 0;
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

int bel::next() 
{
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
	return &table[curentrecord];
}


int  main(void) {
	bel tef;
	int i;
	belrow *p = NULL;

	tef.append("ivanka", "stoqnov", 456465L);
	tef.append("ivan", "dimov", 456423L);
	/*tef.append("ivanka", "norris", 456465L);
	tef.append("ivanka", "todorova", 456445L);
	tef.append("ivo", "siromahov", 456454L);
	tef.append("ivancho", "putin", 456475L);
	tef.append("vancheto", "harly", 456499L); */

	tef.first();
	p = tef.get();
	// if(tef.first=tef.last)
	  // i=-1;
	while (i != -1)
		printf("\nname=%s, fam=%s, tel=%lu", p->name, p->fam, p->tel);
	i = tef.next();
	p = tef.get();
}

getch();


}


//tef.prev();
//tef.last();


