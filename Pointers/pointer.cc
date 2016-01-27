#include<stdio.h>
#include<conio.h>
int main()
{
	char *p1="the world is";
	char *p2="the world is beautiful";
	p1=p2;

	p2="beautiful";

	printf("%s\n",p1);
	printf("%s",p2);
	getch();
	return 0;
}
