// notebook_cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

const int MAX_STRING_LENGTH = 255;
const int NUMBER_OF_CONTACTS = 50;

class Contact
{
	string name;
	string phoneNumber;

public:
	Contact()
	{
	}

	Contact (string newName, string newPhoneNumber)
	{
		name = newName;
		phoneNumber = newPhoneNumber;
	}
	
	string getName()
	{
		return name;
	}

	string getPhoneNumber()
	{
		return phoneNumber;
	}

	string description()
	{
		return "Name: " + name + "\nPhone: " + phoneNumber;
	}
};

class ContactList
{
	Contact* notebook;
	int count;
public:
	ContactList()
	{
		count = 0;
		notebook = new Contact[NUMBER_OF_CONTACTS];
	}
	
	void AddNewContact(string newName, string newPhoneNumber = "000000000")
	{
		Contact newContact = Contact(newName, newPhoneNumber);
		notebook[count] = newContact;
		count++;
	}

	void PrintContactList()
	{
		if (count == 0)
		{
			cout << "Contact list is empty\n";
			return;
		}

		for(int i = 0; i < count; i++)
		{
			Contact currentContact = notebook[i];
			cout << "\n" << currentContact.description() << "\n";
		}
	}

	void Find(string searchName)					
	{
		int countFindings = 0;
		for (int i = 0; i < count; i++)
		{
			Contact currentContact = notebook[i];
			string contactName = currentContact.getName();
			if (contactName.rfind(searchName, 0) == 0)
			{
				countFindings++;
			}
		}

		cout << countFindings;
	}

	void ShowUsage()
	{
		cout << "Please enter the command in the following format: commandName [contactName] [contactPhone]\n";
		cout << "possible values of commandName: Add, Find, Exit\n";
		cout << "contactName - string value (name of contact)\ncontactPhone - optional string value (contact phone number)\n";
	}
};

int main()
{
	ContactList contactList = ContactList();
	contactList.ShowUsage();
	char* commandString;
	while (true)
	{
		commandString = new char[MAX_STRING_LENGTH];
		cout << "->";
		cin.getline(commandString, MAX_STRING_LENGTH);
		char* context;
		char* command = strtok_s(commandString, " ", &context);
		char* name = strtok_s(NULL, " ", &context);
		char* phone = strtok_s(NULL, " ", &context);
		if (strncmp((char *)"Exit", command, MAX_STRING_LENGTH) == 0)
		{
			break;
		}

		if (name != NULL)
		{
			if (strncmp((char*)"Add", command, MAX_STRING_LENGTH) == 0)
			{
				phone == NULL ? contactList.AddNewContact(name) : contactList.AddNewContact(name, phone);
				contactList.PrintContactList();
			}
			if (strncmp((char*)"Find", command, MAX_STRING_LENGTH) == 0)
			{
				contactList.Find(name);
			}
		}
		else
		{
			cout << "Wrong command!\n";
		}
		cout << "\n";
	}
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
