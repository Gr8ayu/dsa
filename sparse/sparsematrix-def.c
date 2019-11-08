#include "sparsematrix-dec.h"

SP insert(SP head, int row, int col, int value)
{
	SP new_node = (SP)malloc(sizeof(struct node));
	new_node->row=row;
	new_node->col=col;
	new_node->value=value;
	new_node->prev=NULL;
	new_node->next=NULL;
	if(head==NULL)
		return new_node;
	SP temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new_node;
	new_node->prev=temp;
	return head;
}

void display(SP head, int m, int n)
{
	SP temp;
	int i,j,flag=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			temp=head;
			while(temp!=NULL)
			{
				if(temp->row==i && temp->col==j)
				{
					printf("%d\t",temp->value);
					flag=1;
				}
				temp=temp->next;
			}
			if(flag!=1)
				printf("0\t");
			flag=0;
		}
		printf("\n");
	}
}
