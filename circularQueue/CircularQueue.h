#include<stdio.h>


#define N 5 

struct queue{
    int data[N];
    int front ;
    int rear ;  
    
};


void enqueue(struct queue* ,int );

int dequeue(struct queue *);

void display(struct queue );
