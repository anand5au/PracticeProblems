#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i=1;
	char *str=NULL;
	printf("Program strated\n");
	str = (char *)calloc(4,sizeof(char));
	getch();
	for(;i<=5;i++)
	{
		strcat(str,"1234");
		if(i!=5)
			str = (char *)realloc(str,sizeof(str)+4);
	}
	printf("Final String: %s",str);
	getch();
	return 0;
}



