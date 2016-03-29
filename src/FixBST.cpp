/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

//Fixes based on sorting of inordered elements in live checking without creating an new array.
void inorder_prev(node * root, node ** k, node ** n1, node ** n2){
	if (root == NULL)
		return;
	inorder_prev(root->left, k, n1, n2);
	if (k[0] != NULL){
		if (root->data < k[0]->data){
			if (*n1 == NULL)
			{
				*n1 = k[0];
				*n2 = root;
			}
			else
				*n2 = root;
		}
	}
	k[0] = root;
	inorder_prev(root->right, k, n1, n2);
}

void swap_nodes(struct node *a, struct node *b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void fix_bst(node * root){
	if (root == NULL)
		return;
	node * n1 = NULL, *n2 = NULL, **k = (node **)malloc(sizeof(node));
	k[0] = NULL;
	inorder_prev(root, k, &n1, &n2);
	swap_nodes(n1, n2);
}