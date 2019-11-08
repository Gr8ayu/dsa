#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node * next;

};

struct queue{
    struct node* front ;
    struct node * rear ;  
    int size ;
};


void enqueue(struct queue* Q,int value){
   
   
    struct node * temp = (struct node *) malloc(sizeof(struct node *));
    
    temp->data = value;
    temp->next = (*Q).front ;
    
    
    if((*Q).front == NULL && (*Q).rear == NULL){
        
        
        (*Q).rear = temp;
        (*Q).front = temp;
    
    }
    //else if((*Q).rear == (*Q).size-1){
    //printf("\nQueue Overflow");
    //}
    
    else{
        
        (*Q).rear->next = temp;
        (*Q).rear = temp;
    }
}

int dequeue(struct queue *Q){

    if((*Q).front == NULL && (*Q).rear == NULL){
        printf("\n Queue is empty");
    }
    
    else if((*Q).front == (*Q).rear){
        struct node* temp = (*Q).front;
        int data = temp->data;
        
        (*Q).front = NULL;
        (*Q).rear = NULL;
            
        free(temp);
        return data;
    }
    else{
        struct node* temp = (*Q).front;
        int data = temp->data;
        (*Q).front = (*Q).front->next ;
        (*Q).rear->next = (*Q).front;
        
                
        free(temp);
        return data;
    
    }
    
    
    



}


void display(struct queue Q){
    struct node * i;
    printf("\n------------------------------\n");
    if(Q.front == NULL && Q.rear == NULL){
        printf("Empty Queue");
        //printf("\nDEBUG: front:%d, rear%d\n",Q.front,Q.rear);
        printf("\n------------------------------\n");
        return;
    }
    
    for (i = Q.front; i != NULL; i = i->next)
    {
        printf("%d--",i->data);
    }
    
    //printf("\nDEBUG: front:%d, rear%d\n",Q.front,Q.rear);

    printf("\n------------------------------\n");
}







int main(){

    struct queue Q;
    Q.front = NULL;
    Q.rear = NULL;
    //Q.size = 15;
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
