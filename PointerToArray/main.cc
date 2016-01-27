#include <stdio.h>
#include <string.h>

int main()
{
	int (*array)[10]={0};
	int b[10][10];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			b[i][j]=10;

	array = (int(*)[10])&b;

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			printf("Array element is %d\n",array[i][j]);
	return 0;
}
