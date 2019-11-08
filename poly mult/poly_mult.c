#include "LinkedList.h"

void displayPoly(Node* LL){

int x = 0;
printf("Polynomial is :");
while(LL != NULL)
    {
    if(LL->data != 0){
        printf("%d(x^%d) + ",LL->data, x);
    }
    x++;
    LL = LL->next;
    }
    printf("\b\b\n");
}


Node* poly_mult(Node* LL1, Node* LL2){
	Node* head1 = LL1;
	Node* head2 = LL2;
	displayPoly(head1);
	displayPoly(head2);
	int i,j;
	char c;
	Node* head3 = NULL ;

	while(head1 != NULL){
		head3 = insertLL(head3,0,0);
		head1 = head1->next;
		//display(head3);
	}
	while(head2 != NULL){
		head3 = insertLL(head3,0,0);
		head2 = head2->next;
		//display(head3);
	}

	display(head3);
	for ( i = 0,head1 = LL1; head1 != NULL; head1 = head1->next, i++)
	{
		for ( j = 0, head2 = LL2; head2 != NULL; head2 = head2->next, j++)
		{
			updateVal(head3, i+j, getVal(head3,i+j) + head1->data*head2->data  );
		}
	}

	return head3;




}


 int main()
{
/*
	 Node* LL2 = NULL;
	  LL2 = insertLL(LL2,-1,6);
	
	  LL2 = insertLL(LL2,-1,3);
	  LL2 = insertLL(LL2,-1,2);
	  LL2 = insertLL(LL2,-1,0);
	  display(LL2);
	  LL2 = removeLL(LL2,0);
	  LL2 = removeLL(LL2,5);
	  LL2 = removeLL(LL2,1);
	 printf("\n%d", getVal(LL2,0) );
	 	printf("\n%d\n", getVal(LL2,1) );
	 		printf("\n%d\n", getVal(LL2,5) );
	
	 display(LL2);
*/
	Node* LL1 = NULL;
	int m,n,x;
    printf("\nEnter degree of polynomial 1 : ");
    scanf("%d",&m);
    for(int i = 0; i<=m ; i++){
        printf("\n\t Enter coefficient of x^%d : ",i);
        scanf("%d",&x);
        LL1 = insertLL(LL1,-1,x);
    }
    displayPoly(LL1);

	Node* LL2 = NULL;
	printf("Enter degree of polynomial 2 : ");
    scanf("%d",&n);
    for(int i = 0; i<=n ; i++){
        printf("\n\t Enter coefficient of x^%d : ",i);
        scanf("%d",&x);
        LL2 = insertLL(LL2,-1,x);
    } 
    
	Node* LL3 = NULL;	 
	
	LL3 = poly_mult(LL1,LL2);
	displayPoly(LL3);















	return 0;
}
