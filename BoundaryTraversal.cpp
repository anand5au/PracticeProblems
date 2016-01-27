#include "stdafx.h"
#include "tree.h"
#include <conio.h>

void PrintLeaves(Node root)
{
	if(!root)
		return;
	PrintLeaves(root->left);
	if(!root->left && !root->right) // leaf node
		printf("C%d ",root->value);
	PrintLeaves(root->right);
}

void LeftBoundary(Node root) // top down
{
	if(!root)
		return;
	if(root->left)
	{
		printf("L%d ",root->value);
		LeftBoundary(root->left);
	}
	else if(root->right)
	{
		printf("LR%d ",root->value);
		LeftBoundary(root->right);
	}
}

void RightBoundary(Node root) // bottom up
{
	if(!root)
		return;
	if(root->right)
	{
		RightBoundary(root->right);
		printf("R%d ",root->value);
	}
	else if(root->left)
	{
		RightBoundary(root->left);
		printf("RL%d ",root->value);
	}
}

void BoundaryTraversal(Node root)
{
	if(!root)
		return;
	printf("B%d ",root->value);
	LeftBoundary(root->left);
	PrintLeaves(root->left);
	PrintLeaves(root->right);
	RightBoundary(root->right);
}

int main()
{
	Node root = NULL;
	root = Insert(root,8);
	root = Insert(root,6);
	root = Insert(root,7);
	root = Insert(root,9);
	root = Insert(root,2);
	root = Insert(root,4);
	root = Insert(root,11);
	root = Insert(root,10);
	root = Insert(root,12);
	root = Insert(root,5);
	root = Insert(root,3);
	root = Insert(root,1);
	
	PrintTree(root);
	printf("\nBoundary order:\n");
	BoundaryTraversal(root);
	getch();
	return 0;
}

