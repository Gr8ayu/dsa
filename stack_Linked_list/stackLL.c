#include "stackLL.h"

void push(struct node** stackaddr,int data){
    struct node* temp = (struct node*) malloc(sizeof(struct node *));
    temp->data = data;
    temp->next = *stackaddr;
    *stackaddr = temp;  
    //return temp;

}

void pop(struct node ** stackaddr){
    if (*stackaddr == NULL){
        printf("Stack Empty\n");    
        return;
    }   
    
    struct node* temp = *stackaddr;
    *stackaddr = temp->next;
    
    printf("%d deleted \n", temp->data);
    
    free(temp);
    
}

void display(struct node* stack){
    
    if(stack == NULL){
    printf("Stack Empty ");
    }   
        
    while(stack != NULL){
        printf("%d ] ",stack->data);
        stack = stack->next;
    }
    
    printf("\n");

}

