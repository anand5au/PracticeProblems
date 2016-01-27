
#ifndef STACK_H_
#define STACK_H_

#include "tree.h"

#define MAX_SIZE 100

//typedef struct TreeNode* Node;

class Stack
{
	Node data[MAX_SIZE];
	int top;

public:
	Stack()
	{
		top = -1;
	}

	~Stack()
	{

	}

	bool IsEmpty()
	{
		return top == -1;
	}

	bool IsFull()
	{
		return top == MAX_SIZE - 1;
	}

	void Push(Node val)
	{
		if(!IsFull())
			data[++top] = val;
	}

	Node Pop()
	{
		if(!IsEmpty())
			return(data[top--]);
		else
			return 0;
	}
};


#endif /* STACK_H_ */
