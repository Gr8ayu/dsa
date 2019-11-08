#include<stdio.h>
#include<stdlib.h>


typedef struct node Node;

 struct node{

	int data;
	Node* next;
};

Node* insertLL(Node* ,int , int );
Node* removeLL(Node* ,int );
int getVal(Node* ,int );
void updateVal(Node* ,int , int);
void display(Node*);
