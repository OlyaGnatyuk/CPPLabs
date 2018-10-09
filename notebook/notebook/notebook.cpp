// notebook.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_STRING_LENGTH = 255;

struct contact
{
	char *name;
	char *phoneNumber;
	contact *next;
};

void AddNewContact(contact **head, char *name, char *phoneNumber = (char *)"0000000000")
{
	contact *newContact = new contact;
	newContact->name = name;
	newContact->phoneNumber = phoneNumber;
	newContact->next = (*head);
	(*head) = newContact;
}

void PrintContactList(contact *head)
{
	if (head == NULL)
	{
		cout << "Contact list is empty\n";
		return;
	}
	
	contact *current = head;

	while (current != NULL)
	{
		cout << "Name: " << current->name << "\n" << "Phone: " << current->phoneNumber << "\n";
		current = current->next;
	}
}

void showUsage()
{
	cout << "Please enter the command in the following format: commandName contactName [contactPhone]\n";
	cout << "possible values of commandName: Add, Find\n";
	cout << "contactName - string value (name of contact)\ncontactPhone - optional string value (contact phone number)\n";
}

int main()
{
	contact *head = NULL;
	PrintContactList(head);
	showUsage();
	char commandString[MAX_STRING_LENGTH];
	cin >> commandString;
	char *context;
	char *command = strtok_s(commandString, " ", &context);
	char *name = strtok_s(commandString, " ", &context);
	//char* phone;

	if (strncmp((char *)"Add", command, MAX_STRING_LENGTH) == 0)
	{
		AddNewContact(&head, (char *)"name");
		/*cout << name << "\n";
		cout << phone << "\n";*/
	}

	PrintContactList(head);
	return 0;
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
