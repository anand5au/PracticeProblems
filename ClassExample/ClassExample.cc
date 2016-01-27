#include<stdio.h>

class add
{
	int num1, num2, sum;
public:
	add()
	{
		printf("Parameter Without constructor:\n");
		num1 = '\0';
		num2 = '\0';
		sum = '\0';
	}

	add(int s1 , int s2)
	{
		printf("Parameterized constructor:\n");
		num1 = s1;
		num2 = s2;
		sum = 0;
	}
	add(add &a)
	{
		printf("Copy constructor:\n");
		num1 = a.num1;
		num2 = a.num2;
		sum = a.sum;
	}

	void getdata()
	{
	   printf("Get Number-1: ");
	   scanf("%d",&num1);
	   printf("Get Number-2: ");
	   scanf("%d",&num2);
	}

	void addition(add &b)
	{
		sum = num1+num2+b.num1+b.num2;
	}

	add addition()
	{
		add a(5,6);
		sum = num1+num2+a.num1+a.num2;
		return *this;
	}

	void putData()
	{
		printf("Number-1 = %d\tNumber-2 = %d\tSum = %d\n",num1,num2,sum);
	}
};

int main()
{
	add a,b(10,20),c(b);
	a.getdata();
	a.addition(b);
	b=c.addition();
	c.addition();
	printf("Object a: ");
	a.putData();
	printf("Object b: ");
	b.putData();
	printf("Object c: ");
	c.putData();

	return 0;
}
