
// stack array

#include"stack_arr.h"




int main(){
    int size =100;
    int A[size],top=-1,v=1,k;
    do {
        printf("Enter the operation : 1.PUSH  2.POP 3.DISPLAY 0 EXIT: ");
        scanf("%d",&v);
        switch(v){
            case 0:
            exit(0);
            
            case 1:printf("Enter the value : ");
                    scanf("%d",&k);
                    push(A,size,&top,k);
            break;
            case 2: pop(A,size,&top); 
            break;
            case 3: display(A,size,&top);
            break;
            default: 
                    printf("\n\n You made invalid choice\n");
                    continue;
        
        }
    }while(v != 0);
}




