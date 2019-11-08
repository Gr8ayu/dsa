#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

typedef struct StackNodeLL{
    Tree* data;
    struct StackNodeLL* next;
} stackNode;


void push(stackNode** ,Tree* );

Tree* pop(stackNode ** );

int peek(stackNode* );

int isEmpty(stackNode*);

void display(stackNode* );
