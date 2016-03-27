/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int heightOfTree(node * root){
	if (root == NULL)
		return 0;
	else{
		int LHeight = heightOfTree(root->left);
		int RHeight = heightOfTree(root->right);
		//Expanding the tree with larger height...
		return LHeight > RHeight ? LHeight + 1 : RHeight + 1;
	}
}

void elementsInLevel(node * root, int level, int * arr, int * pos){
	if (root == NULL)
		return;
	if (level == 1)
		arr[(*pos)++] = root->data;
	else
	{   //Reducing the level in order to reach the leaf node to trace the elements in level...
		elementsInLevel(root->right, level - 1, arr, pos);
		elementsInLevel(root->left, level - 1, arr, pos);
	}
}

void gen_array(node * root, int * arr){
	int h = heightOfTree(root);
	int pos = 0;
	for (int i = 1; i <= h; i++){
		elementsInLevel(root, i, arr, &pos);
	}
}

int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int * arr = (int *)malloc(sizeof(int)* 20);
	gen_array(root, arr);
	return arr;
}
