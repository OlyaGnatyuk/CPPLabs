// fibonachi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

long int StringToInt(const char *str, bool &formatError, bool &overflowError);
void Fibonacci(long int n);

int main(int argc, char *argv[])
{
	printf("This program outputs Fibonacci numbers \n");

	if (argc < 2)
	{
		printf("Please enter a number for upper limit, example: fibonachi.exe 123");
		return 0;
	}

	bool formatError, overflowError;
	long int upLimit = StringToInt(argv[1], formatError, overflowError);
	
	if (overflowError)
	{
		printf("Argument #1 is too big number\n.");
		return 1;
	}
	
	if (formatError)
	{
		printf("Argument #1 is not a number\n.");
		return 1;
	}

	if (upLimit < 1)
	{
		printf("Argument #1 should be greater or equal to 1\n.");
		return 1;
	}
	
	if (upLimit > 0)
	{
		Fibonacci(upLimit);
	}
	return 0;
}

long int StringToInt(const char *str, bool &formatError, bool &overflowError)
{
	char *pLastChar = NULL;
	long int param = strtol(str, &pLastChar, 10);
	formatError = ((*str == '\0') || (*pLastChar != '\0'));
	overflowError = (((param == LONG_MAX) || (param == LONG_MIN)) && (errno == ERANGE));
	return param;
}

void Fibonacci(long int n)
{
	printf("0, 1, ");

	int count = 2;

	for (long int numberMinus2 = 0, numberMinus1 = 1, numFib = 1; numFib <= n; numFib = numberMinus2 + numberMinus1)
	{
		count++;
		numberMinus2 = numberMinus1; 
		numberMinus1 = numFib;
		bool fifthNumber = (count % 5 == 0);
		bool lastNumber = ((numberMinus2 + numberMinus1) > n);
		if (lastNumber)
		{
			printf("%d", numFib);
		}
		else
			if (fifthNumber)
			{
				printf("%d\n", numFib);
			}
			else
			{
				printf("%d, ", numFib);
			}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
