#include<stdio.h>

void insert(int A[],int m, int c){

        int no = c;
        c= 2*c +3;
        int index  = c%m;
        
        do{
                if(A[index] == 0){
                        A[index ] = no;
                        printf("\n Inserted %d at %d",no,index);
                        return;
                }
                else{
                        index = (index+1)%m;
                }
        }while(index != c%m);
        
        printf("\n All places full");
}

int main(){
        int m = 10,i;
        int A[m];
        
        for (i = 0; i < m; i += 1)
        {
                A[i] = 0;
        }     
        
        int a ;
        printf("nos : ");
        scanf("%d",&a);
        
        printf("values : ");
        while(a--){
                int c;
                
                scanf("%d",&c);
                
                
                insert(A,m,c);
                
                printf("\n");
                for (i = 0; i < m; i += 1)
                {
                        
                        if(A[i] == 0){
                                printf(" - ");
                        }
                        else{
                                printf(" %d ",A[i]);
                        }
                }
                
                
                
        }        
        
        
}
