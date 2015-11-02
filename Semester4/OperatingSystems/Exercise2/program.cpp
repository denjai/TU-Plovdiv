#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct student
{
	int fnum;
	char fname[20];
	char lname[20];
};

struct list_item
{
	struct student *st;
	list_item *next;
};

int main()
{
	struct list_item *head_pointer, *p, *p1, *p2;
	int t = 0, i, j;
	struct student *k;
	head_pointer = NULL;

	do
	{
		printf("vuvedete:\n '1' za vuvejdane na element\n '2' za tursene \n '3' za iztrivane \n '4' za krai\n");
		scanf("%d", &i);

		if (i == 1)
			do
			{
				t = 0;
				k = (struct student*)malloc(sizeof(struct student));

				printf("\nvuvedete  fakulteten nomer na student na student:");
				scanf("%d", &k->fnum);
				fflush(stdin);
				printf("\n vuvedete  lichno ime na student:");
				gets(k->lname);
				printf("\n vuvedete  familno ime na student:");
				gets(k->fname);

				p = (struct list_item*)malloc(sizeof(struct list_item));
				p->st = k;

				if (head_pointer == NULL)
				{
					head_pointer = p;
					p->next = NULL;
					t = 1;
				}
				else
				{
					for (p1 = head_pointer, p2 = p1; p1 != NULL; p1 = p1->next)
					{
						if (p1->st->fnum > p->st->fnum)
						{
							if (p1 == head_pointer)
							{
								head_pointer = p;
								p->next = p1;
								t = 1;
								break;
							}
							else
							{
								p2->next = p;
								p->next = p1;
								t = 1;
								break;
							}
						}
						p2 = p1;
					}
				}

				if (t == 0)
				{
					p2->next = p;
					p->next = NULL;
				}
				printf("za novo vuvejdane natisnete '1' za krai '0':");
				scanf("%d", &j);
			} while (j == 1);

			if (i == 2)
			{
				do
				{
					printf("vuvedete fakulteten nomer za tursene:");
					scanf("%d", &t);
					for (p1 = head_pointer; p1 != NULL; p1 = p1->next)
					{
						if (p1->st->fnum == t)
						{
							puts(p1->st->lname);
							puts(p1->st->fname);
						}
					}
					printf("za novo vuvejdane natisnete '1' za krai '0'");
					scanf("%d", &j);
				} while (j == 1);
			}
			if (i == 7)
			{
				for (p1 = head_pointer; p1 != NULL; p1 = p1->next)
				{
					printf("%d \t", p1->st->fnum);
				}
			}
			if (i == 3)
			{
				do
				{
					printf("vuvedete fakulteten nomer za triene");
					scanf("%d", &t);
					for (p1 = head_pointer, p2 = NULL; p1 != NULL; p1 = p1->next)
					{
						if (p1->st->fnum == t)
						{
							if (p1 == head_pointer)
							{
								head_pointer = head_pointer->next;
								free(p1);
								break;
							}
							else
							{
								p2->next = p1->next;
								free(p1);
								break;
							}
						}
						p2 = p1;
					}
					printf("za novo vuvejdane natisnete '1' za krai '0'");
					scanf("%d", &j);
				} while (j == 1);
			}
	} while (i != 4);
	return 0;
}
