#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
	int data;
	struct node *next;
}*NODE;

NODE create(NODE);
NODE insert(NODE, int);
NODE addterm(NODE, NODE);
void display(NODE);

NODE create(NODE head)
{
	head->data=0;
	head->next=head;
	return head;
}

NODE insert(NODE head, int num)
{
	NODE new_node = (NODE)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=NULL;
	new_node->next=head->next;
	head->next=new_node;
	return head;
}

NODE addterm(NODE num1, NODE num2)
{
	int carry=0,sum=0;
	NODE first, second;
	first=num1->next;
	second=num2->next;
	while(first!=num1 || second!=num2)
	{
		int a=first->data,b=second->data;
		if(first==num1)
			a=0;
		else if(second==num2)
			b=0;
		sum = carry + a + b;
		carry = (sum>=10)?1:0;
		sum = sum%10;
		res = insert(res, sum);
		if(first!=num1)
			first=num1->next;
		if(second!=num2)
			second=num2->next;
	}
	return res;
}

void display(NODE head)
{
	NODE temp=head->next;
	while(temp!=head);
		display(temp);
	printf("%d",temp->data);
}
		
int main()
{
	int num, i, flag=1;
	char* str1, str2;
	NODE num1, num2, res;
	num1=create(num1);
	num2=create(num2);
	res=create(res);
	do
	{
	printf("Enter the first number: ");
	scanf("%s",str1);
	for(i=0;i<strlen(str1);i++)
	{
		num = str1[i] - '0';
		if(isdigit(str1[i]))
			num1 = insert(num1, num);
		else
			flag=0;
	}
	if(flag!=1)
		printf("Invalid entry\n");
	}while(flag!=1);
	flag=1;
	do
	{
	printf("Enter the second number: ");
	scanf("%s",str2);
	for(i=0;i<strlen(str2);i++)
	{
		num = str2[i] - '0';
		if(isdigit(str2[i]))
			num2 = insert(num2, num);
		else
			flag=0;
	}
	if(flag!=1)
		printf("Invalid entry\n");
	}while(flag!=1);
	res=addterm(num1, num2);
	display(res);
	printf("\n");
	return 0;
}
