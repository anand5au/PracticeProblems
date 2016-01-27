
#include "tree.h"

#define MAX_SIZE 100

class Queue
{
	Node data[MAX_SIZE];
	int head;
	int tail;

public:
	Queue()
	{
		head = tail = -1;
	}

	~Queue()
	{

	}

	bool IsEmpty()
	{
		return (tail==-1) || (head>tail);
	}

	bool IsFull()
	{
		return tail == (MAX_SIZE - 1);
	}

	void EnQueue(Node val)
	{
		if(!IsFull())
		{
			data[++tail] = val;
			if(head == -1) head++;
		}
	}

	Node Dequeue()
	{
		if(!IsEmpty())
			return(data[head++]);
		else
			return NULL;
	}

	Node Head()
	{
		if(!IsEmpty())
			return(data[head]);
		else
			return NULL;
	}
};

