//stack ll
#include "stackLL.h"


int main(){
    struct node* stack = NULL;
    int v,k;       
    
 
    do {
        printf("Enter the operation : 1.PUSH  2.POP 3.DISPLAY 0 EXIT: ");
        scanf("%d",&v);
        switch(v){
            case 0:
            exit(0);
            
            case 1:printf("Enter the value : ");
                    scanf("%d",&k);
                    push(&stack,k);
            break;
            case 2: pop(&stack); 
            break;
            case 3: display(stack);
            break;
            default: 
                    printf("\n\n You made invalid choice\n");
                    continue;
        
        }
    }while(v != 0);
}

