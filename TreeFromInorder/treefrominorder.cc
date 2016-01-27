#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct TreeNode
{
int a;
struct TreeNode *left;
struct TreeNode *right;
};

typedef struct TreeNode Tree;

void PrintTree(Tree *node)
{
if(!node)
return;
PrintTree(node->left);
printf("%d ",node->a);
PrintTree(node->right);
}

Tree *NewNode(int data)
{
Tree *node = NULL;
node = (Tree *)malloc(sizeof(Tree));
node->a = data;
node->left = NULL;
node->right = NULL;
return node;
}

Tree *Construct(Tree **tree,int data)
{
if(!*tree)
{
*tree = NewNode(data);
}
else if(data > (*tree)->a)
{
Tree *node = NewNode(data);
node->left = *tree;
*tree = node;
}
else if(data < (*tree)->a)
{
(*tree)->right = Construct(&((*tree)->right),data);
}
return *tree;
}

void DestroyTree(Tree *tree)
{
if(tree)
{
DestroyTree(tree->left);
DestroyTree(tree->right);
free(tree);
}
}

int main()
{
int array[] = {3,7,2,9,8,6,10,5,8,4};
int size = sizeof(array)/sizeof(array[0]);
Tree *tree = NULL;
for(int i=0;i<size;i++)
tree = Construct(&tree,array[i]);
printf("Tree is :\n");
PrintTree(tree);
DestroyTree(tree);
getch();
return 0;
}
