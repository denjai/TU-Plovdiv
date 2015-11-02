#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct student
{
	int fnum;
	char fname[20];
	char lname[20];
};

struct bnode
{
	struct student *st;
	bnode *left, *right;
};

void ins(struct bnode* t, struct bnode *p)
{
	if (p->st->fnum < t->st->fnum)
	{
		if (t->left != NULL)
			ins(t->left, p);
		else
		{
			t->left = p;
			t->left->left = NULL;
			t->left->right = NULL;
		}
	}
	else if (p->st->fnum >= t->st->fnum)
	{
		if (t->right != NULL)
			ins(t->right, p);
		else
		{
			t->right = p;
			t->right->left = NULL;
			t->right->right = NULL;
		}
	}
}


struct bnode* search(struct bnode* t, int q)
{
	if (t != NULL)
	{
		if (t->st->fnum == q)
		{
			return (t);
		}

		if (t->st->fnum > q)
		{
			search(t->left, q);
		}
		else
		{
			search(t->right, q);
		}
	}
	else
	{
		return NULL;
	}

}

struct bnode* del(struct bnode* t, int q) {
	struct bnode* s;
	if (t != NULL)
	{
		if (t->st->fnum == q)
		{
			if (t->left == NULL&&t->right == NULL)
			{
				t = NULL;
			}

			if (t->left != NULL&&t->right == NULL)
			{
				t = t->left;
			}
			if (t->left == NULL&&t->right != NULL)
			{
				t = t->right;
			}
			if (t->left != NULL&&t->right != NULL)
			{
				s = t;
				while (s->right->left != NULL)
				{
					s = s->right;
				}
				t->st = s->left->st;
				s->left = NULL;
			}
		}

		if (t->st->fnum > q)
		{
			del(t->left, q);
		}
		else
		{
			del(t->right, q);
		}
	}
	else
	{
		printf("durvoto e prazno ili fakultetniq nomer ne e nameren");
	}
}



int main()
{
	struct bnode *root_pointer = NULL, *p, *s, *t;
	struct student *k;
	int n, i, q;

	do
	{
		printf("vuvedete:\n 1 za vuvejdane\n 2 za tursene\n 3 za iztrivane\n 4 za krai\n");
		scanf("%d", &i);
		if (i == 1)
		{

			p = (struct bnode*)malloc(sizeof(struct bnode));
			k = (struct student*)malloc(sizeof(struct student));
			p->st = k;

			printf("vuvedete fakulteten nomer:");
			scanf("%d", &p->st->fnum);
			printf("vuvedete first name:");
			fflush(stdin);
			fgets(p->st->fname, 20, stdin);
			printf("vuvedete last name:");
			fflush(stdin);
			fgets(p->st->lname, 20, stdin);
			p->left = NULL;
			p->right = NULL;

			if (root_pointer != NULL)
			{
				ins(root_pointer, p);
			}
			else
			{
				root_pointer = p;
				root_pointer->left = NULL;
				root_pointer->right = NULL;
			}
		}
		if (i == 2)
		{
			printf("vuvedete fakulteten nomer za tursene:");
			scanf("%d", &q);
			s = search(root_pointer, q);

			if (s != NULL)
			{
				puts(s->st->fname);
				puts(s->st->lname);
			}
			else
			{
				printf("durvoto e prazno ili fakultetniq nomer ne e nameren");
			}
		}
		if (i == 3)
		{
			printf("vuvedete fakulteten nomer za triene:");
			scanf("%d", &q);

			root_pointer = del(root_pointer, q);
		}
	} while (i != 4);

	getch();
	return 0;
}

