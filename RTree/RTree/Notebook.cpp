#include "pch.h"
#include "Notebook.h"

using namespace std;

Notebook::Notebook()
{
	head = new Node();
}

int Notebook::SearchLetter(Node* node, char* searchString, int chPoz)
{
	int ch = searchString[chPoz];
	if (node == NULL) return 0;
	int nextCharPosition = chPoz + 1;
	int nextChar = searchString[nextCharPosition];
	if (nextChar == 0)
	{
		return node->numberOfWords;
	}
	return SearchLetter(node->next[nextChar], searchString, nextCharPosition);
}

void Notebook::InsertLetter(Node** node, char* word, int chPoz)
{
	int ch = word[chPoz];
	if (ch == 0)
	{
		return;
	}
	if ((*node) == NULL)
	{
		(*node) = new Node;
	}
	else
	{
		(*node)->numberOfWords++;
	}
	
	int nextCharPosition = chPoz + 1;
	int nextChar = word[nextCharPosition];
	if (nextChar == 0)
	{
		(*node)->setIsEnd(true);
	}
	InsertLetter(&((*node)->next[nextChar]), word, nextCharPosition);
}


int Notebook::Search(char* searchString)
{
	int firstChar = searchString[0];
	return SearchLetter(head->next[firstChar], searchString, 0);
}

void Notebook::Insert(char* newWord)
{
	int firstChar = newWord[0];
	InsertLetter(&(head->next[firstChar]), newWord, 0);
}

void Notebook::ShowUsage()
{
	cout << "Please enter the command in the following format: commandName [contactName]\n";
	cout << "possible values of commandName: Add, Find, Exit\n";
	cout << "contactName - string value (name of contact)\n";
}
