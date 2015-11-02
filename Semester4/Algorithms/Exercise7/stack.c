#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct stack1
{
	char symbol;
	struct bracket * prev;
} *sp = NULL;

int add(char c)
{
	struct bracket *ptr;
	ptr = (struct bracket *)malloc(sizeof(struct bracket));
	if (!ptr)
		return 0;
	ptr->symbol = c;
	ptr->prev = sp;
	sp = ptr;
	return 1;
}

int checkStack(char c)
{
	struct bracket *p;
	char mirror = '\0';
	switch (c)
	{
	case ')':
		mirror = '(';
		break;
	case '}':
		mirror = '{';
		break;
	case ']':
		mirror = '[';
		break;
	}
	if (sp != NULL && sp->symbol == mirror)
	{
		p = sp;
		sp = sp->prev;
		free(p);
		return 1;
	}
	else
		return 0;
}
