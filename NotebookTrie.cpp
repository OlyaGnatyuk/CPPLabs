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

#include "stdafx.h"
#include "notebook.h"

using namespace std;

const int MAX_STRING_LENGTH = 255;

int main()
{
	Notebook notebook = Notebook();
	notebook.ShowUsage();
	char* commandString;
	while (true)
	{
		commandString = new char[MAX_STRING_LENGTH];
		cout << "->";
		cin.getline(commandString, MAX_STRING_LENGTH);
		char* context;
		char* command = strtok_s(commandString, " ", &context);
		char* name = strtok_s(NULL, " ", &context);
		if (strncmp((char *)"Exit", command, MAX_STRING_LENGTH) == 0)
		{
			break;
		}

		if (name != NULL)
		{
			if (strncmp((char*)"Add", command, MAX_STRING_LENGTH) == 0)
			{
				notebook.Insert(name);
			}
			
			else if (strncmp((char*)"Find", command, MAX_STRING_LENGTH) == 0)
			{
				cout << "Number of " << name << " = " << notebook.Search(name) << endl;
			}
			else
			{
				cout << "Wrong command!\n";
			}
		}
		else
		{
			cout << "Missing parametr\n";
		}
		cout << "\n";
	}
	return 0;
}