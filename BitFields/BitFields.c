#include<stdio.h>
#include<conio.h>

struct naren
{
	int a:8;
	unsigned b:8;
};

int main()
{
	float aa = '?';
	struct naren n;
	n.a = 5;
	n.b = 10;
	char *p = &n;
	*(p+2) = 1;
	printf("size of n: %d,%d,%d,%d\n",p,*p,*(p+1),*(p+2));
	printf("float value: %f",aa);
	getch();
	return 0;
}
