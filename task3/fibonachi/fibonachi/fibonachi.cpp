// fibonachi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

long int StringToInt(const char *str, bool &error);
void Fibonacci(unsigned long int n);

int main(int argc, char *argv[])
{
	printf("This program outputs Fibonacci numbers.\n");
	printf("Usage: fibonachi.exe n\n");
	printf("n - integer parameter from the range 1 - 2147483647\n");

	if (argc < 2)
	{
		return 0;
	}

	bool error = false;
	long int upLimit = StringToInt(argv[1], error);
	
	if (error)
	{
		return 1;
	}
	
	if (upLimit < 1)
	{
		printf("Argument #1 should be greater or equal to 1\n.");
		return 1;
	}
	
	Fibonacci((unsigned long)upLimit);
	return 0;
}

long int StringToInt(const char *str, bool &error)
{
	char *pLastChar = NULL;
	long int param = strtol(str, &pLastChar, 10);
	if ((*str == '\0') || (*pLastChar != '\0'))
	{
		printf("Argument #1 is not a number\n.");
		error = true;
	}
	if ((param > LONG_MAX) || (param < LONG_MIN))
	{
		printf("Argument #1 is too big number\n.");
		error = true;
	}
	return param;
}

void Fibonacci(unsigned long int n)
{
	unsigned long int numberMinus2 = 0;
	unsigned long int numberMinus1 = 1;
	unsigned long int numFib = numberMinus2 + numberMinus1;
	int count = 2;

	printf("%d, %d, ", numberMinus2, numberMinus1);

	while (numFib <= n)
	{
		count++;
		bool fifthNumber = (count % 5 == 0);
		if ((numberMinus1 + numFib) > n)
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
		numberMinus2 = numberMinus1;
		numberMinus1 = numFib;
		numFib = numberMinus2 + numberMinus1;
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
