#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode* Node;
int vsum[10];
static int count=0;
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
	printf("%d",root->value);
	PrintTree(root->left);
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

void VerticalSum(Node root, int level,int vsum[])
{
	if(root == NULL)
		return;
	VerticalSum(root->left,level-1,vsum);
	vsum[level]+=root->value;
	VerticalSum(root->right,level+1,vsum);
}

void KthLargest(Node root,int k)
{
	if(root == NULL)
		return;
	KthLargest(root->right,k);
	count++;
	if(count == k)
	{
		printf("Kth Largest Element is %d\n",root->value);
		return;
	}
	KthLargest(root->left,k);
}

int IsBST(Node root)
{
	if(!root)
		return 1;
	if(root->left)
	{
		if(root->value >= root->left->value)
			return IsBST(root->left);
		else
			return 0;
	}
	if(root->right)
	{
		printf("right half\n");
		if(root->value <= root->right->value)
			return IsBST(root->right);
		else
			return 0;
	}
	return 1;
}

int main()
{
	Node root;
	int i;
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

	VerticalSum(root,0,vsum);
	for(i=0;i<10;i++)
	{
		printf("\nvsum: %d\n",vsum[i]);
	}
	KthLargest(root,6);
	printf("\nIsBST() - %d",IsBST(root));
	DestroyTree(root);
	return 0;
}
