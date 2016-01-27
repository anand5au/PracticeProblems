#ifndef TREE_H_
#define TREE_H_

#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
	struct TreeNode *next;
};

typedef struct TreeNode* Node;

Node Insert(Node root,int val)
{
	if(root == NULL)
	{
		Node temp;
		temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		temp->value = val;
		temp->left = NULL;
		temp->right = NULL;
		temp->next = NULL;
		return temp;
	}
	if(val > root->value)
		root->right =  Insert(root->right,val);
	else
		root->left =  Insert(root->left,val);
	return root;
}

void PrintTree(Node root)
{
	if(!root)
		return;
	PrintTree(root->left);
	printf("%d",root->value);
	PrintTree(root->right);
}

void DestroyTree(Node root)
{
	if(root)
	{
		DestroyTree(root->left);
		DestroyTree(root->right);
		free(root);
	}
}

#endif /* TREE_H_ */
