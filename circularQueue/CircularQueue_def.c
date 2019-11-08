#include "CircularQueue.h"


/*
Enqueue function to inert data at end of queue

params:
     struct queue* Q : address of Queue to be mordified
     int value : value to be appended at end of queue


*/
void enqueue(struct queue* Q,int value){

    if((*Q).front == -1 && (*Q).rear == -1){
        (*Q).rear = 0;
        (*Q).front = 0;
        (*Q).data[(*Q).rear] = value;
    
    }
    else if( ((*Q).rear == N-1) && ( (*Q).front == 0 )  ){
        printf("\nQueue Overflow\n");
        return;
    }
    else if( ((*Q).rear == (*Q).front -1  ) ){
        printf("\nQueue Overflow\n");
        return;
    }
    
    else if( (*Q).rear == N-1 ){
        (*Q).rear = 0;
        (*Q).data[(*Q).rear] = value;
    }
    
    else{
        (*Q).data[++((*Q).rear)] = value;
    }
}

/*
Dequeue function to remove data from front end of queue

params:
     struct queue* Q : address of Queue to be mordified
     int value : value to be appended at end of queue


*/

int dequeue(struct queue *Q){

    if((*Q).front == -1 && (*Q).rear == -1){
        printf("\n Queue is empty");
        return 0;
    }
   
    
    else if((*Q).front == (*Q).rear){
        int temp = (*Q).data[(*Q).rear];
        (*Q).front = -1;
        (*Q).rear = -1;
        return temp;
    }
    
    else if((*Q).rear == 0  ){
        (*Q).rear = N-1;
        return (*Q).data[0];
    }
    
    
    else{
    return (*Q).data[((*Q).front)++];
    
    }
    
    
    



}

/*
function to display content of Queue

params:

struct queue Q : queue whose data is to be displayed

*/

void display(struct queue Q){
    int i;
    
    printf("\n------------------------------\n");
    
    
    // checking if the queue is empty
    if(Q.front == -1 && Q.rear == -1){
        
        printf("Empty Queue");
        printf("\nDEBUG: front:%d, rear:%d\n",Q.front,Q.rear);
        printf("\n------------------------------\n");
        return;
    }
    
    
    // Displaying data from circular queue if queue is not empty
    printf("<<| ");
    for (i = Q.front ; ; i = (i + 1)%N  )
    {   
        printf("%d | ",Q.data[i]);
        if(i == Q.rear){break;}
    }
    printf(" \b\b\b|<< ");
    
    printf("\nDEBUG: front:%d, rear:%d\n",Q.front,Q.rear);

    printf("\n------------------------------\n");
}
