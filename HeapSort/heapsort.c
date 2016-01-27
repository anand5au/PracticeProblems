#include<stdio.h>

int a[] = {0x7FFFFFFF,2,-2,3,-3,8,-8,7,9,-9,0,-7}; // Note: array is based on index 1 for our convenience
int size = (sizeof(a)/sizeof(int)) - 1;

void printArray(int a[],int length)
{
	int i = 1;
	for(;i<=length;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void sink(int index)
{
	while(index <= size/2)
	{
		int newIndex = 2*index;
		if((newIndex < size) && (a[newIndex] < a[newIndex+1]))
			newIndex++;
		if(a[newIndex] < a[index])
			break;
		swap(&a[index],&a[newIndex]);
		index = newIndex;
	}
}

/********************** Part of Prioroty queue ******************/
void swim(int index)
{
	while((index > 1) && (a[index/2] < a[index]))
	{
		swap(&a[index/2],&a[index]);
		index /= 2;
	}
}
/****************************************************************/

int main()
{
	int i=size/2;
	// forming maxheap
	for(;i>=1;i--)
		sink(i);
	// removing max element and putting in its position
	while(size>1)
	{
		swap(&a[1],&a[size--]);
		sink(1);
	}
	printArray(a,(sizeof(a)/sizeof(int))-1);
	return 0;
}
