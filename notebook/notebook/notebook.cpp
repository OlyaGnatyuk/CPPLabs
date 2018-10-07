// notebook.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

struct contact
{
	char *name;
	char *phoneNumber;
	contact *next;
};

void AddNewContact(contact *head, contact *newContact)
{
	newContact->next = head;
	head = newContact;
}

void PrintContactList(contact *head)
{
	if (head == NULL)
	{
		printf("Contact list is empty");
		return;
	}
	contact *next = head;
	while (next != NULL)
	{
		printf("Name: %s\nPhone: %s\n\n", next->name, next->phoneNumber);
		next = next->next;
	}
}

int main()
{
	contact *firstContact = NULL;
	PrintContactList(firstContact);
	contact *newContact = new contact;
	newContact->name = (char*)"Olya";
	newContact->phoneNumber = (char*)"12345678";
	AddNewContact(firstContact, newContact);
	PrintContactList(firstContact);
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
