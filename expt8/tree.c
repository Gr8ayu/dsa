#include "tree.h"
#include <stdlib.h>


Tree* createTree(int x){
	Tree* root = (Tree*) malloc(sizeof(Tree));
	root->data = x;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void tree_insert_left(Tree* root, int x){
	if (root == NULL)
	{
		return;
	}

	else{
		Tree* temp = (Tree*) malloc(sizeof(Tree));
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		root->left = temp;
		
	}
}

void tree_insert_right(Tree* root, int x){
	if (root == NULL)
	{
		return;
	}

	else{		
		Tree* temp = (Tree*) malloc(sizeof(Tree));
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		root->right = temp;
		
	}
}



void tree_append_left(Tree* root, Tree* x){
	if (root == NULL)
	{
		return;
	}

	else{
		
		root->left = x;
		
	}
}

void tree_append_right(Tree* root, Tree* x){
	if (root == NULL)
	{
		return;
	}

	else{		
		root->right = x;
		
	}
}














Tree* BSTinsert(Tree* root, int x ){
	if(root == NULL){
		
		Tree* temp = (Tree*) malloc(sizeof(Tree));
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	else if(root->data >= x){
		root->left = BSTinsert(root->left,x);
	}
	else{
		root->right = BSTinsert(root->right,x);	
	}
	return root;
}


void preorder(Tree* root){
	if(root == NULL){
		return;
	}

	printf("%c ", root->data );
	preorder(root->left);
	preorder(root->right);
}

void inorder(Tree* root){
	if(root == NULL){
		return;
	}

	inorder(root->left);
	printf(" %c ", root->data );
	inorder(root->right);
}

void postorder(Tree* root){
	if(root == NULL){
		return;
	}

	postorder(root->left);
	postorder(root->right);
	printf(" %c ", root->data );
}