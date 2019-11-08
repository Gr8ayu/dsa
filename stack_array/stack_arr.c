#include"stack_arr.h"

void push(int A[], int size, int *top,int value){
    if (*top >= size-1){
        printf("Stack Overflow\n"); 
        return;
    }
    
    *top = *top + 1;
    A[*top] = value;

}

void pop(int A[], int size, int *top){
    if (*top <= -1){
        printf("Stack Empty\n");    
        return;
    }   
    printf("%d deleted from index %d\n",A[*top],*top);
    *top = *top - 1;
}

void display(int A[], int size, int *top){
    int index = *top;
    printf("Stack is : ");
    for (int i = index; i>=0 ; i--){
        printf("%d ] ",A[i]);
    }
    printf("\n");
    


}
