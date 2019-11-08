#include<stdio.h>



struct queue{
    int data[15];
    int front ;
    int rear ;  
    int size ;
};


void enqueue(struct queue* Q,int value){

    if((*Q).front == -1 && (*Q).rear == -1){
        (*Q).rear = 0;
        (*Q).front = 0;
        (*Q).data[(*Q).rear] = value;
    
    }
    else if((*Q).rear == (*Q).size-1){
    printf("\nQueue Overflow");
    }
    
    else{
        (*Q).data[++((*Q).rear)] = value;
    }
}

int dequeue(struct queue *Q){
    if((*Q).front == -1 && (*Q).rear == -1){
        printf("\n Queue is empty");
    }
    else if((*Q).front == (*Q).rear){
        int temp = (*Q).data[(*Q).rear];
        (*Q).front = -1;
        (*Q).rear = -1;
        return temp;
    }
    else{
    return (*Q).data[((*Q).front)++];
    
    }
    
    
    



}


void display(struct queue Q){
    int i;
    printf("\n------------------------------\n");
    if(Q.front == -1 && Q.rear == -1){
        printf("Empty Queue");
        printf("\nDEBUG: front:%d, rear%d\n",Q.front,Q.rear);
        printf("\n------------------------------\n");
        return;
    }
    
    for (i = Q.front; i <= Q.rear; i += 1)
    {
        printf("%d--",Q.data[i]);
    }
    
    printf("\nDEBUG: front:%d, rear%d\n",Q.front,Q.rear);

    printf("\n------------------------------\n");
}







int main(){

    struct queue Q;
    Q.front = -1;
    Q.rear = -1;
    Q.size = 15;
    int sel, data;
    
    while(1){
        printf("1. enqueue 2.dequeue : ");
        scanf("%d",&sel);
        switch(sel){
            case 1: 
                
                printf("Enter data : ");
                scanf("%d",&data);
                enqueue(&Q,data);
                display(Q);
                break;
            case 2:
                dequeue(&Q);
                display(Q);
    
        }   
    
    
    
    
    }    
    
    
    



}










