#pragma argsused
#include <vcl.h>
#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include<conio.h>
#include "bel.h"

int  main()
{
	bel tef(2);
	int i = 0;
	belrow *p = NULL;
	tef.append("ivanka", "stoqnov", 456465L);
	tef.append("ivan", "dimov", 456423L);
	tef.append("ivanka", "norris", 456465L);
	tef.append("ivanka", "todorova", 456445L);
	tef.append("ivo", "siromahov", 456454L);
	tef.append("ivancho", "putin", 456475L);
	tef.append("vancheto", "harly", 456499L);

	tef.last();
	p = tef.get();

	while (p&&i != -1)
	{
		printf("\nname=%s, fam=%s, tel=%lu", p->name, p->fam, p->tel);
		i = tef.prev();
		p = tef.get();
	}

	getch();
	return 0;
}
