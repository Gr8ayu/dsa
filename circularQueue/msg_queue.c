#include "CircularQueue.h"


int main(){

    struct queue Q;
    Q.front = -1;
    Q.rear = -1;
    
    int sel;
    char data[100];
    
    while(1){
    
        printf("1. enqueue 2.dequeue, 3.Display: ");
        scanf("%d",&sel);
        
        switch(sel){
            case 1: 
                
                printf("Enter data : ");
                scanf("%s",&data);
                enqueue(&Q,data);
                //display(Q);
                break;
                
            case 2:
                dequeue(&Q);
                //display(Q);
                break;
                
                
            case 3:
                display(Q);
    
        }   
    
    
    
    
    }    
    
    
    



}
