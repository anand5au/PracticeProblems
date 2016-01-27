#include <stdio.h>

int main()
{
	unsigned int a=0,b=0;
	scanf("%d",&a);
	b= (0xAAAAAAAA & (a<<1)) | (0x55555555 & (a>>1));
	printf("\n%d",b);
	return 0;
}
