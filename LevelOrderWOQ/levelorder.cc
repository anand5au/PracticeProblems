#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Node GetNext(Node root)
{
	if(!root)
		return NULL;
	Node temp = root->next;
	while(temp)
	{
		if(temp->left)
			return temp->left;
		if(temp->right)
			return temp->right;
		temp=temp->next;
	}
	return NULL;
}

void RecurLevelOrder(Node root)
{
	if(!root)
		return;

	RecurLevelOrder(root->next);
	if(!root->left && !root->right)
	{
		RecurLevelOrder(GetNext(root));
	}
	else if(root->left)
	{
		root->left->next = (root->right)?root->right:GetNext(root);
		RecurLevelOrder(root->left);
	}
	if(root->right)
	{
		root->right->next = GetNext(root);
		RecurLevelOrder(root->right);
	}

}

void LevelOrder(Node root)
{
	if(root)
	{
		root->next = NULL;
		RecurLevelOrder(root);
	}

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
	root = Insert(root,13);
	root = Insert(root,5);
	root = Insert(root,3);
	root = Insert(root,1);

	PrintTree(root);
	printf("\nLevel order:\n");
	LevelOrder(root);
	PrintTree(root);
	return 0;
}
