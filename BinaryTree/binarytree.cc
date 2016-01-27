#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
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
		return temp;
	}
	if((root->value == 0 && val == 1) || (root->value == 1 && val == 0))
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

int main()
{
	Node root;
	root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->value = 0;
	root->left = NULL;
	root->right = NULL;
	root = Insert(root,0);
	root = Insert(root,1);
	root = Insert(root,1);
	root = Insert(root,0);
	root = Insert(root,1);
	root = Insert(root,0);
	root = Insert(root,1);
	root = Insert(root,1);
	root = Insert(root,0);
	PrintTree(root);

	DestroyTree(root);
	return 0;
}
