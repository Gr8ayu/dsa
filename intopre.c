#include<stdio.h>
#include<string.h>
#include<ctype.h>

//struct Stack {
//    char A[100];
    
//};
int A[100];
int top = -1;

void push(char c){
    A[++top] = c; 
}

char pop(){
    if(top>=0){
    top--;
    return A[top+1];
    } 
    else {return 0;}
}

char peek(){
    if(top>=0){
    return A[top];
    } 
    else {return 0;}
}

char isempty(){
    if(top>=0){
    return 0;
    } 
    else {return 1;}
}




int operatorPrec(char C){
    if(C=='^' || C=='$'){return 5;}
    
    if(C=='*' || C=='/'){return 4;}
    
    if(C=='+' || C=='-'){return 3;}
    
    //if(C=='^' || C='$'){return 5;}
    
    return 0;
    
}



int main(){
    
    char exp[100];
    int i,index=0;
    printf("enter infix :");
    gets(exp);
    char postfix[100];
    for (i = 0; i < strlen(exp); i += 1)
    {
        
        //OPERAND
        
        
        if(exp[i]=='('){
            push('(');
        }
        
        else if(isalnum(exp[i])){
            postfix[index++] = exp[i];
        }
        
        
        else if(operatorPrec(exp[i]) != 0 ){
            
            char x = pop();
            while(operatorPrec(x) !=0 && operatorPrec(x) >= operatorPrec(exp[i]))
                {
                    postfix[index++] = x;
                    x = pop();
                }
                 
        
            push(x);
            push(exp[i]);
        }
        
        
        else if(exp[i] == ')' ){
            char x = pop();
            while(x != '('){
                postfix[index++] = x;
                x = pop();
            }
        }
        
    }
    
    while(!isempty()){
    postfix[index++] = pop();
    postfix[index] = 0;
    }
        
    
    printf("here is exp : ");
    puts(postfix);
    
}




