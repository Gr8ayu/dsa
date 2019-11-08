#include "stackLL.h"

void push(stackNode** stackaddr,Tree* data){
    stackNode* temp = (stackNode*) malloc(sizeof(stackNode *));
    temp->data = data;
    temp->next = *stackaddr;
    *stackaddr = temp;  
    //return temp;

}

Tree* pop(stackNode ** stackaddr){
    if (*stackaddr == NULL){
        printf("Stack Empty\n");    
        return 0 ;
    }   
    
    stackNode* temp = *stackaddr;
    *stackaddr = temp->next;
    
    Tree* i = temp->data;
    // printf("%d deleted \n", temp->data);
    
    free(temp);
    return i;
}

int peek(stackNode* stack){
    if (stack == NULL){
        return -1;
    }   

    return stack->data->data;
    
}

void display(stackNode* stack){
    
    if(stack == NULL){
    printf("Stack Empty ");
    }   
        
    while(stack != NULL){
        // printf("%d ] ",stack->data);
        stack = stack->next;
    }
    
    printf("\n");

}

int isEmpty(stackNode* stack){
    if (stack == NULL){
        return 1;
    }  
    return 0; 
}
