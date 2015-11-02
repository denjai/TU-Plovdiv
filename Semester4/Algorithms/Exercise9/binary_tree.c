#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
	char key;
	struct node * left;
	struct node * right;
};

void preOrder(struct node *v) {
	if (v != NULL) {
		printf("%c\t", v->key);
		preOrder(v->left);
		preOrder(v->right);
	}

}

void inOrder(struct node *v) {
	if (v != NULL) {
		inOrder(v->left);
		printf("%c\t", v->key);
		inOrder(v->right);
	}

}

void postOrder(struct node *v) {
	if (v != NULL) {

		postOrder(v->left);
		postOrder(v->right);
		printf("%c\t", v->key);
	}

}

void readtree(struct node ** p, char &x) {

	char y, z;
	struct node * q1, *q2;

	if (*p == NULL)
	{
		printf("Vyvedi korena");
		scanf("%c", &x);
		(*p) = (struct node *)malloc(sizeof(struct node));
		(*p)->key = x;
	}
	getchar();

	printf("\nVyvedi liav naslednik na %c", x);
	z = getchar();
	getchar();

	printf("\nVyvedi desen naslednik na %c", x);
	y = getchar();


	if (z != '0')
	{
		q1 = (struct node *)malloc(sizeof(struct node));
		q1->key = z;
		(*p)->left = q1;
		readtree(&q1, z);
	}
	else
		(*p)->left = NULL;


	if (y != '0')
	{
		q2 = (struct node *)malloc(sizeof(struct node));
		q2->key = y;
		(*p)->right = q2;
		readtree(&q2, y);
	}
	else
		(*p)->right = NULL;
}

void printtree(struct node * p, int delta)
{
	int i;
	if (p != NULL)
	{
		printtree(p->left, delta + 1);
		for (i = 1; i <= delta; i++)
			printf("\t");
		printf("%c", p->key);
		printf("\n");
		printtree(p->right, delta + 1);
	}
}

int main()
{
	struct node * root, ** proot;
	proot = &root;
	char k, *pk;
	pk = &k;
	root = NULL;
	readtree(proot, *pk);
	printtree(root, 0);

	printf("\n");
	preOrder(root);
	printf("\n\n");
	inOrder(root);
	printf("\n\n");
	postOrder(root);

	getch();

	return 0;
}