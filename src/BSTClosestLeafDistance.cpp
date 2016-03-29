/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

bool isLeaf(node * root){
	if (root == NULL)
		return false;
	if (root->left == NULL &&root->right == NULL)
		return true;
	return false;
}

node * return_correct_sub_root(node * root, node * n1, node * n2){
	if (n1 == NULL || n2 == NULL)
		return NULL;
	else{
		if (n1->data < root->data && n2->data < root->data){
			return return_correct_sub_root(root->left, n1, n2);
		}
		else if (n1->data > root->data && n2->data > root->data){
			return return_correct_sub_root(root->right, n1, n2);
		}
		else
		{
			return root;
		}
	}
}

void GD_from_root(node * node1, node * node2, int count, int * res){
	if (node1 == NULL || node2 == NULL)
		return;
	if (node1 == node2){
		*res = count;
		return;
	}
	else if (node1->data < node2->data){
		GD_from_root(node1->right, node2, count + 1, res);
	}
	else if (node1->data > node2->data){
		GD_from_root(node1->left, node2, count + 1, res);
	}
}

int dist_btwn_nodes(node * root, node * node1, node * node2){
	int dis1 = 0, dis2 = 0;
	node * ans = return_correct_sub_root(root, node1, node2);
	GD_from_root(ans, node1, 0, &dis1);
	GD_from_root(ans, node2, 0, &dis2);
	return dis1 + dis2;
}

void checkWithAll(node * m_root, node * root, node * temp, int * res){
	if (root == NULL)
		return;
	if (isLeaf(root)){
		int dist = dist_btwn_nodes(m_root, root, temp);
		if (*res == -1)
			*res = dist;
		else if (dist < *res)
			*res = dist;
		return;
	}
	else{
		checkWithAll(m_root, root->left, temp, res);
		checkWithAll(m_root, root->right, temp, res);
		return;
	}
}

int get_closest_leaf_distance(node * root, node * temp){
	int ans = -1;
	if (root == NULL || temp == NULL)
		return ans;
	checkWithAll(root, root, temp, &ans);
	return ans;
}
