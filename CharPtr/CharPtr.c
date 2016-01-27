#include<stdio.h>

int main()
{
	char *c = "Anand";
	char a[] = "Kumar";
	printf("ca - %s %s\n",c,a);
	a[2] = 'n';
	printf("ca - %s %s\n",c,a);
	int ai=0;
	printf("%d\n",(int)(&ai + 1) - (int)(&ai));
	return 0;
}
