include "sparsematrix-dec.h"

int main()
{
	SP head=NULL;
	int m, n, ct, i, row, col, value;
	printf("Enter the number of rows and columns: ");
	scanf("%d %d",&m,&n);
	printf("Enter the number of valid elements: ");
	scanf("%d",&ct);
	for(i=0;i<ct;i++)
	{
		printf("Enter the row, column, value of %dth element:\n",i+1);
		scanf("%d %d %d",&row,&col,&value);
		if(row>=m || col>=n)
		{
			printf("Invalid entry\n");
			i--;
		}
		else
			head=insert(head, row, col, value);
	}
	printf("Sparse matrix is: \n");
	display(head,m,n);
	return 0;
}
