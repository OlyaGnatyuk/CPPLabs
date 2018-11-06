/*Дан файл с текстом. Напишите функцию которая находит минимальное и максимальное расстояние между двумя словами.
Расстояние измеряется числом слов (одна буква тоже слово).

Example1:

$text = "Today is very good a sunny day";
$word1 = 'day';
$word2 = 'Today';

min distance: 5
max distance: 5

Example2:

$text = "Today is very good a sunny day and tomorrow will be very good day too.";
$word1 = 'day';
$word2 = 'Today';

min distance: 5
max distance: 12

Решите задачу максимально эффективным способом, оцените сложность полученного алгоритма по O(n). Укажите общее потраченное время на решение задачи (обдумывание, кодирование, тестирование, форматирование, оптимизация и пр.)
Используйте любой язык. Если будут вопросы, пишите.

Оформляйте код по-людски: кто, что, зачем, комментарии и т.д.*/

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

// Функция, которая находит минимальное и максимальное расстояние между двумя словами
void readFileData(string filename, string firstWord, string secondWord)
{
	// filestream variable file 
	fstream file;
	string currentWord;
	int minimumDistance = INT_MAX;
	int maximumDistance;

	int firstPositionFirstWord = -1;
	int firstPositionSecondWord = -1;
	int lastPositionFirstWord = -1;
	int lastPositionSecondWord = -1;
	
	int currentWordPosition = 0;
	
	// Подгружаем файл последовательными частями
	file.open(filename.c_str());

	while (file >> currentWord)
	{
		if (currentWord.compare(firstWord) == 0)
		{
			lastPositionFirstWord = currentWordPosition;
			int distance = lastPositionFirstWord - lastPositionSecondWord - 1;
			if (lastPositionSecondWord >= 0 && minimumDistance > distance)
			{
				minimumDistance = distance;
			}
			if (firstPositionFirstWord < 0)
			{
				firstPositionFirstWord = currentWordPosition;
			}
		}
		else if (currentWord.compare(secondWord) == 0)
		{
			lastPositionSecondWord = currentWordPosition;
			int distance = lastPositionSecondWord - lastPositionFirstWord - 1;
			if (lastPositionFirstWord >= 0 && minimumDistance > distance)
			{
				minimumDistance = distance;
			}
			if (firstPositionSecondWord < 0)
			{
				firstPositionSecondWord = currentWordPosition;
			}
		}
		currentWordPosition++;
	}

	int maxDiff1 = abs(lastPositionSecondWord - firstPositionFirstWord) - 1;
	int maxDiff2 = abs(lastPositionFirstWord - firstPositionSecondWord) - 1;
	if (maxDiff1 > maxDiff2)
	{
		maximumDistance = maxDiff1;
	}
	else maximumDistance = maxDiff2;

	if ((firstPositionFirstWord >= 0) && (firstPositionSecondWord >= 0))
	{
		cout << "Minimum distance=" << minimumDistance << endl;
		cout << "Maximum distance=" << maximumDistance;
	}
	else
	{
		cout << "One of words has not been found";
	}
}

int main()
{
    cout << "Please enter two words:\n->";
	string firstWord, secondWord;
	cin >> firstWord >> secondWord;
	readFileData("d:\\file.txt", firstWord, secondWord);
}
