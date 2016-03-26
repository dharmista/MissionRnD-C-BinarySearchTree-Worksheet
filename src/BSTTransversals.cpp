/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void inorder_wrapper(node * root, int * arr, int * pos){
	if (root == NULL)
		return;
	inorder_wrapper(root->left, arr, pos);
	arr[(*pos)++] = root->data;
	inorder_wrapper(root->right, arr, pos);
}

void preorder_wrapper(node * root, int * arr, int * pos){
	if (root == NULL)
		return;
	arr[(*pos)++] = root->data;
	preorder_wrapper(root->left, arr, pos);
	preorder_wrapper(root->right, arr, pos);
}

void postorder_wrapper(node * root, int * arr, int * pos){
	if (root == NULL)
		return;
	postorder_wrapper(root->left, arr, pos);
	postorder_wrapper(root->right, arr, pos);
	arr[(*pos)++] = root->data;
}

void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL){
		arr = NULL;
		return;
	}
	int pos = 0;
	inorder_wrapper(root, arr, &pos);
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL){
		arr = NULL;
		return;
	}
	int pos = 0;
	preorder_wrapper(root, arr, &pos);
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL){
		arr = NULL;
		return;
	}
	int pos = 0;
	postorder_wrapper(root, arr, &pos);
}

