#include "stdafx.h"
#include <conio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

void LevelOrder(Node root)
{
	Queue *q = new Queue();
	q->EnQueue(root);
	while(!q->IsEmpty())
	{
		static int currLevel = 1, nextLevel = 0;
		Node temp = q->Dequeue();
		printf("%d ",temp->value);
		currLevel--;
		if(temp->left)
		{
			q->EnQueue(temp->left);
			nextLevel++;
		}
		if(temp->right)
		{
			q->EnQueue(temp->right);
			nextLevel++;
		}
		if(currLevel == 0)
		{
			printf("\n");
			currLevel = nextLevel;
			nextLevel = 0;
		}
		temp->next = q->Head();
	}
}

int main()
{
	Node root = NULL;
	root = Insert(root,6);
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
	printf("\nLevel order:\n");
	LevelOrder(root);
	Node temp = root;
	while(temp)
	{
		printf("%d ",temp->value);
		temp = temp->next;
	}
	getch();
	return 0;
}

