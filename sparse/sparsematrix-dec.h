#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int row, col, value;
	struct node *prev, *next;
}*SP;

SP insert(SP head, int row, int col, int value);
void display(SP head, int m, int n);
