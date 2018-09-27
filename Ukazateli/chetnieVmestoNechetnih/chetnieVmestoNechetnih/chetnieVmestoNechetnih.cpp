// chetnieVmestoNechetnih.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

void instantiateArray(int *array, int arraySize);
void exchangeOddValues(int *array, int arraySize);
void printArray(int *array, int arraySize);

int main()
{
	const int SizeOfArray = 12;
	int *pamyat = new int[SizeOfArray];
	
	instantiateArray(pamyat, SizeOfArray);

	printArray(pamyat, SizeOfArray);

	exchangeOddValues(pamyat, SizeOfArray);

	printf("\n");

	printArray(pamyat, SizeOfArray);

	delete pamyat;
}

void instantiateArray(int *array, int arraySize)
{
	for (int i = 0; i < arraySize; ++i)
	{
		array[i] = i + 1;
	}
}

void exchangeOddValues(int *array, int arraySize)
{
	int even;

	for (int i = 0; i < (arraySize - 1); i += 2)
	{
		even = array[i];
		array[i] = array[i + 1];
		array[i + 1] = even;
	}
}

void printArray(int *array, int arraySize)
{
	for (int i = 0; i < arraySize; ++i)
	{
		printf("%d  ", *(array++));
	}
}