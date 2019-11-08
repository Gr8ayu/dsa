#include <stdio.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;

}Tree;

	void insert(Tree* , int );
Tree* createTree(int x);
	void tree_insert_left(Tree*, int);
	void tree_insert_right(Tree*, int);

	void tree_append_left(Tree*, Tree*);
	void tree_append_right(Tree*, Tree*);

	Tree* BSTinsert(Tree* , int );
void preorder(Tree*);
void postorder(Tree*);
void inorder(Tree*);
