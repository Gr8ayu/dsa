#include<stdio.h>


#define N 5 

typedef struct
{
    char data[N][100];
    int front ;
    int rear ;  
    
}queue;


void enqueue( queue* ,char * );

void dequeue( queue *);

void display( queue );
