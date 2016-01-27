#include <stdio.h>

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void printArray(int a[],int length)
{
	printf("Please read the array in reverse order!!!\n");
	while(length)
	{
		printf("%d ",a[length-1]);
		length--;
	}
}

int main()
{
	int a[] = {-1,0,-2,0,6,-5,0,-3,-4};

	int head=0,pass=0;
	while(pass<2)
	{
		int tail = (sizeof(a)/sizeof(int)) - 1;
		while(head<=tail)
		{
			if(pass ? (a[head]==0) : (a[head]<0))
			{
				head++;
				continue;
			}
			else
			{
				if(pass ? (a[tail]==0) : (a[tail]<0))
				{
					swap(&a[head],&a[tail]);
					head++;
				}
				tail--;
			}
		}
		pass++;
	}
	printArray(a,(sizeof(a)/sizeof(int)));
	return 0;
}
