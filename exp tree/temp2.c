
#include<stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
	
Tree* a = createTree('e');

printf("inserted %c to right in %c\n", 'A', a->data );
tree_insert_right( a, 'A');


printf("inserted %c to left in %c\n", 'B', a->data );
tree_insert_left( a, 'B');

inorder( a );



}