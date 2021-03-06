#include "pch.h"
#include <iostream>

int DigitsSum(int i)
{
	int sum = 0;
	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int StringToInt(const char *str, bool &err)
{
	char *pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("This program displays numbers that are divisible by the sum of their digits. \n");
		printf("Please use program with first integer parameter for upper limit, example: task2.exe 123");
		return 0;
	}

	bool error;
	int upLimit = StringToInt(argv[1], error);
	
	if (error)
	{
		printf("Argument #1 is not a number\n.");
		return 1;
	}

	if (upLimit < 1)
	{
		printf("Argument #1 should be greater or equal to 1\n.");
		return 1;
	}

	for (int x = 0; x <= upLimit; ++x)
	{
		int sum = DigitsSum(x);
		if ((sum != 0) && (x % sum == 0))
		{
			printf("%d\n", x);
		}
	}
	return 0;
}