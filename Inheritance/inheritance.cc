#include <stdio.h>

class Base
{
	int baseData;

public:
	Base()
	{
		printf("Default base constructor\n");
		baseData = 0;
	}

	Base(int data)
	{
		printf("Parameterized base constructor\n");
		baseData = data;
	}

	virtual ~Base()
	{
		printf("Base Destructor\n");
	}

	void Print()
	{
		printf("Base print - %d\n",baseData);
	}

	virtual void VirtualFunction()
	{
		printf("Base Virtual Function\n");
	}

	//virtual void PureVF() = 0;
};

class Derived : public Base
{
	int derivedData;

public:
	Derived()
	{
		printf("Default derived constructor\n");
		derivedData = 0;
	}

	Derived(int data)
	{
		printf("Parameterized derived constructor\n");
		derivedData = data;
	}

	~Derived()
	{
		printf("Derived Destructor\n");
	}

	void Print()
	{
		printf("Derived print - %d\n",derivedData);
	}

	void VirtualFunction()
	{
		printf("Derived Virtual Function\n");
	}

	virtual void PureVF()
	{
		printf("Pure Virtual Function\n");
	}
};

int main()
{
	printf("Test - 1\n");
	Base *base = new Base();
	base->Print();
	base->VirtualFunction();

	printf("Test - 2\n");
	Derived *derived = new Derived();
	derived->Print();
	derived->VirtualFunction();

	printf("Test - 3\n");
	Base *base1 = new Derived();
	base1->Print();
	base1->VirtualFunction();

	printf("Size of Base, Derived = %d, %d\n",sizeof(Base),sizeof(Derived));
	printf("Size of Base, Derived = %d, %d\n",sizeof(base),sizeof(derived));

	printf("\n");
	delete(base);
	printf("\n");
	delete(derived);
	printf("\n");
	delete(base1);

	return 0;
}
