#include <stdio.h>

class Outer
{
	int outerData;

	Outer()
	{
		printf("Outer Class Constructor\n");
		outerData = 0;
	}

	~Outer()
	{
		printf("Outer Class Destructor\n");
	}

	class Inner
	{
		int innerData;

		Inner()
		{
			printf("Inner Class Constructor\n");
			innerData = 0;
		}

		~Inner()
		{
			printf("Inner Class Destructor\n");
		}
	};

};
