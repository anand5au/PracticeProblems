#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void MaxSubSeq(int array[],int length, int *start, int *end)
{
	long long max_sum = -(((long long)1)<<(8*sizeof(int)));
	long long entire_sum=0;
	int break_point = -1,i=0;

	for(; i<length; i++)
	{
		entire_sum += array[i];
		printf("entire_sum = %lld\n",entire_sum);
		if(max_sum < entire_sum)
		{
			max_sum = entire_sum;
			printf("Max_Sum = %lld\n",max_sum);
			*start = break_point+1;
			*end = i;
		}
		if(entire_sum <= 0)
		{
			entire_sum = 0;
			break_point = i;
		}
	}
}

int main()
{
	int a[] = { 3,2,-3, -3, 1,1,6 };
	int start=0,end=0;
	MaxSubSeq(a,sizeof(a)/sizeof(int),&start,&end);
	printf("Start(%d),end(%d)",start,end);
	return 0;
}
