#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "stack.h"

void Inorder(Node root)
{
	Stack *stack = new Stack();
	stack->Push(root);
	Node temp = root->left;

	while(true)
	{
		while(temp)
		{
			stack->Push(temp);
			temp = temp->left;
		}
		if(stack->IsEmpty())
			break;
		temp = stack->Pop();
		printf("%d ",temp->value);
		temp = temp->right;
	}
}

int main()
{
	Node root;
	root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->value = 6;
	root->left = NULL;
	root->right = NULL;
	root = Insert(root,7);
	root = Insert(root,9);
	root = Insert(root,4);
	root = Insert(root,2);
	root = Insert(root,10);
	root = Insert(root,5);
	root = Insert(root,3);
	root = Insert(root,1);
	root = Insert(root,8);
	PrintTree(root);
	printf("\n");
	Inorder(root);
	DestroyTree(root);
	return 0;
}
