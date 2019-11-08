#include<stdio.h>
#include<string.h>
#include "stackLL.h"
// #include "tree.h"

int priority(char c){
	if(c == '^')
		return 3;
	else if (c=='*' || c =='/')
	{
		return 2;
	}
	else if (c=='+' || c == '-')
	{
		return 1;
	}

	else 
		return 0;
}

int main(int argc, char const *argv[])
{
	
	stackNode* tree_stack = NULL;
	stackNode* op_stack = NULL;

	char A[100];
	printf("enter expression : ");
	scanf("%s",A);

	for (int i = 0; i < strlen(A); ++i)
	{
		// printf(">");
		Tree* element = createTree(A[i]);

		if (priority(element->data) == 0)
		{
			push(&tree_stack, element);
			// printf("pushed %c to TREE\n", element->data );
		}
		else{


			if(isEmpty(op_stack)){
				push(&op_stack, element);
				// printf("pushed %c to OP\n", element->data );

			}
			else if( priority(peek(op_stack)) < priority(element->data)  ){
				push(&op_stack, element);
				// printf("pushed %c to OP\n", element->data );
			}
			else{
				while(priority(peek(op_stack)) >= priority(element->data) ){
					Tree* element2 = pop(&op_stack);
					// printf("poped %c from TREE\n", peek(tree_stack) );
					// printf("inserted %c to right in %c\n", peek(tree_stack), element2->data );
					// tree_append_right(element2, pop(&tree_stack));
					element2->right  = pop(&tree_stack);
					
					// printf("poped %c from TREE\n", peek(tree_stack) );
					// printf("inserted %c to left in %c\n", peek(tree_stack), element2->data );
					// tree_append_left(element2, pop(&tree_stack));
					element2->left  = pop(&tree_stack);

					push(&tree_stack, element2);
					// printf("pushed %c to TREE\n", element2->data );

				}
				push(&op_stack, element);
				// printf("pushed %c to OP\n", element->data );
			}
		}
	}

	while(! isEmpty(op_stack) ){
		Tree* element = pop(&op_stack);
		Tree* x = pop(&tree_stack);

		// printf("poped %c from TREE\n",x->data );
		// printf("inserted %c to right in %c\n", x->data, element->data );
		// tree_append_right( element, x);
		element->right = x;
		
		 x = pop(&tree_stack);

		// printf("poped %c from TREE\n",x->data );
		// printf("inserted %c to right in %c\n", x->data, element->data );
		// tree_append_left(element,x);
		element->left = x;

		// printf("pushed %c to TREE\n", element->data );
		push(&tree_stack, element);
	}

	printf("\nINORDER :");
	Tree* item = pop(&tree_stack); 
	inorder( item);
	printf("\nPREORDER :");
	preorder( item);
	printf("\nPOSTORDER :");
	postorder( item );





	return 0;
}