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
using namespace std;

const int NUMBER_ROUTS = 256;
const int MAX_STRING_LENGTH = 255;

// Класс "Записная книжка"
class Notebook {
private:
	// Структура узла дерева
	struct node
	{
		// Количество возможных веток от каждого узла
		int R = NUMBER_ROUTS;
		// Массив ссылок на дочерние узлы
		node** next;
		// Признак конца слова
		bool isEnd = false;
		// Количество слов, сохраненных с использованием этого узла
		int numberOfWords = 1;
		node()
		{
			// Выделение памяти под массив дочерних узлов
			next = new node*[R];
			// Инициализация массива нулевыми значениями
			for (int i = 0; i < R; i++) next[i] = 0;
		}
	};

	// Псевдоним ссылки на узел
	typedef node* link;
	link head;
	
	// Рекурсивный метод поиска количества сохраненных слов, начинающихся со слова в переменной "searchString"
	// На входе три параметра: головной узел, строка поиска, номер символа в строке поиска
	int searchR(link h, char* searchString, int d)
	{
		// Выделение символа номер d из строки поиска
		int i = searchString[d];
		// Если не передан параметр головного узла - выход
		if (h == 0) return 0;
		// Если достигли последнего символа строки поиска,
		if (i == 0)
		{
			// возвращаем количество слов, сохраненных в головном узле,
			return h->numberOfWords;
		}
		// иначе продолжить поиск следующего символа из строки поиска
		return searchR(h->next[i], searchString, d + 1);
	}

	// Вставка нового слова с использованием рекурсии
	void insertR(link& h, char* word, int d)
	{
		// Выделение символа номер d из строки вставки
		int i = word[d];
		// Если строка закончилась, то завершаем работу
		if (i == 0)
		{
			// Конец слова
			if (h != 0)
			{
				h->isEnd = true;
			}
			return;
		}
			
		// Если не существует узла, 
		if (h == 0)
		{
			// создаем узел
			h = new node;
		}
		else
		{
			// Инкрементируем счетчик сохраненных слов
			h->numberOfWords++;
		}
		// Продолжаем вставлять следующий символ
		insertR(h->next[i], word, d + 1);
	}

public:
	Notebook()
	{
		head = 0;
	}

	// Метод для поиска количества совпадений
	int search(char* searchString)
	{
		return searchR(head, searchString, 0);
	}

	// Метод вставки нового слова
	void insert(char* newWord)
	{
		insertR(head, newWord, 0);
	}

	// Метод класса вывода информации, как использовать программу 
	static void ShowUsage()
	{
		cout << "Please enter the command in the following format: commandName [contactName]\n";
		cout << "possible values of commandName: Add, Find, Exit\n";
		cout << "contactName - string value (name of contact)\n";
	}
};

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
				notebook.insert(name);
			}
			// Действие по команде "Find"
			else if (strncmp((char*)"Find", command, MAX_STRING_LENGTH) == 0)
			{
				// Вывод результата поиска по строке, содержащейся в переменной "name"
				cout << "Number of " << name << " = " << notebook.search(name) << endl;
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

