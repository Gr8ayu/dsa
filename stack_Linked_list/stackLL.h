#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};


void push(struct node** ,int );

void pop(struct node ** );

void display(struct node* );
