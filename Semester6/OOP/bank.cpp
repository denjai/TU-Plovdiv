#include <stdio.h>
#include <string.h>
#include <mem.h>
#include<conio.h>

struct bs
{
	char type[15];
	char iban[25];
	float sum;
};

class bank
{
public:
	bs smetki[10];
	char fname[50];
	char lname[50];
	int count;

	bank(void) { count = 0; }

	void addbs(char *type, char *iban, float sum);
	int remove(char *iban);
	bs* search(char *iban);
	bs* search(float sum);
	float richness();
};

void bank::addbs(char *type, char *iban, float sum)
{
	strcpy(smetki[count].type, type);
	strcpy(smetki[count].iban, iban);
	smetki[count].sum = sum;
	count++;
}

int bank::remove(char *iban)
{
	int f = 0;
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(smetki[i].iban, iban))
		{
			strcpy(smetki[i].iban, smetki[count].iban);
			strcpy(smetki[i].type, smetki[count].type);
			smetki[i].sum = smetki[count].sum;
			smetki[count].iban[0] = 0;
			smetki[count].sum = 0;
			count--;
			f = 1;
		}
	}
	if (f == 1)
		return 1;
	else
		return -1;
}

bs* bank::search(char *iban)
{
	for (int i = 0; i < count; i++)
		if (!strcmp(smetki[i].iban, iban))
			return &smetki[i];
}

bs* bank::search(float sum)
{
	for (int i = 0; i < count; i++)
		if (smetki[i].sum == sum)
			return &smetki[i];
}

float bank::richness()
{
	float money = 0;
	for (int i = 0; i < count; i++)
		money += smetki[i].sum;
	return money;
}

int main()
{

	bank obj[5];

	strcpy(obj[0].fname, "Ivan");
	strcpy(obj[0].lname, "Dimov");
	obj[0].addbs("kredit", "68473fdss5r5", 550.3);
	obj[0].addbs("kredit", "64781241hhh41", 2.5);
	strcpy(obj[1].fname, "Pesho");
	strcpy(obj[1].lname, "Geshov");
	obj[1].addbs("krit", "68473fds5r4", 1500);
	obj[1].addbs("kredit", "64781241hh661", 2563);

	bs* k;
	k = obj[1].search(1500);
	puts(k->type);
	getch();


}
