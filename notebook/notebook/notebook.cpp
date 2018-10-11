
#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_STRING_LENGTH = 255;

struct contact
{
	char* name;
	char* phoneNumber;
	contact* next;
};

void AddNewContact(contact** head, char* name, char* phoneNumber = (char*)"0000000000")				//Односвязный список
{
	contact* newContact = new contact;
	newContact->name = name;
	newContact->phoneNumber = phoneNumber;
	newContact->next = (*head);
	(*head) = newContact;
}

void PrintContactList(contact* current)
{
	if (current == NULL)
	{
		cout << "Contact list is empty\n";
		return;
	}
	
	while (current != NULL)
	{
		cout << "\nName: " << current->name << "\n" << "Phone: " << current->phoneNumber << "\n";
		current = current->next;
	}
}

void ShowUsage()
{
	cout << "Please enter the command in the following format: commandName [contactName] [contactPhone]\n";
	cout << "possible values of commandName: Add, Find, Exit\n";
	cout << "contactName - string value (name of contact)\ncontactPhone - optional string value (contact phone number)\n";
}

void Find(contact* current, char* searchName)					//Обход односвязного списка с сравнением поля структуры со строкой поиска
{
	int count = 0;
	while (current != NULL)
	{
		if (strncmp(searchName, current->name, strlen(searchName)) == 0)
		{
			count++;
		}
		current = current->next;
	}
	
	cout << count;
}

int main()
{
	contact* head = NULL;
	ShowUsage();
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
				phone == NULL ? AddNewContact(&head, name) : AddNewContact(&head, name, phone);
				PrintContactList(head);
			}
			if (strncmp((char*)"Find", command, MAX_STRING_LENGTH) == 0)
			{
				Find(head, name);
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

