/*
Алгоритмическая задача II
Приложение “Записная книжка”. Операции:
1. Добавить имя - новый контакт
2. Искать совпадения - вводим строку, приложение выдаёт сколько контактов
начинается на эту строку.
Язык английский, lowercase. Контакты дважды не повторяются.
Пример:
Add alexey
Add alexander
Find alex -> 2
Find alek -> 0 (нету контактов начинающихся на alek)
Базы данных конечно не использовать. Считаем что все контакты помещаются в
оперативной памяти.
Дать оценку сложности алгоритма поиска O(n).
Указать затраченное время. В пояснении к коду в общих чертах описать ваш способ
хранения и поиска контактов.

Оценка сложности алгоритма поиска O(n Log(R)).

*/
#include "pch.h"
#include <iostream>
#include "Notebook.h"

using namespace std;

const int MAX_STRING_LENGTH = 255;

int main()
{
	// Создание экземпляра класса "Записная книжка"
	Notebook notebook = Notebook();
	// Вызов метода класса для вывода информации, как использовать программу
	notebook.ShowUsage();
	// Переменная для хранения введенной команды с консоли
	char* commandString;
	// Бесконечный цикл для ввода команд с консоли
	while (true)
	{
		// Выделение памяти для введенной команды
		commandString = new char[MAX_STRING_LENGTH];
		cout << "->";
		// Ввод команды с консоли с сохранением в переменную
		cin.getline(commandString, MAX_STRING_LENGTH);
		char* context;
		// Получение первого слова из введенной команды с использованием в качестве разделителя "пробел"
		char* command = strtok_s(commandString, " ", &context);
		// Получение второго слова из введенной команды с использованием в качестве разделителя "пробел"
		char* name = strtok_s(NULL, " ", &context);
		// Прерывание бесконечного цикла в случае введения команды "Exit"
		if (strncmp((char *)"Exit", command, MAX_STRING_LENGTH) == 0)
		{
			break;
		}

		// Проверка на наличие второго слова в строке введенной команды
		if (name != NULL)
		{
			// Действие по команде "Add"
			if (strncmp((char*)"Add", command, MAX_STRING_LENGTH) == 0)
			{
				// Добавление имени в справочник
				notebook.Insert(name);
			}
			// Действие по команде "Find"
			else if (strncmp((char*)"Find", command, MAX_STRING_LENGTH) == 0)
			{
				// Вывод результата поиска по строке, содержащейся в переменной "name"
				cout << "Number of " << name << " = " << notebook.Search(name) << endl;
			}
			// Действие при нераспознанной команде
			else
			{
				cout << "Wrong command!\n";
			}
		}
		// Отсутствие второго слова
		else
		{
			cout << "Missing parametr\n";
		}
		cout << "\n";
	}
	return 0;
}

