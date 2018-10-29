
#include "notebook.h"

using namespace std;

Notebook::Notebook()
{
	head = NULL;
}

int Notebook::SearchLetter(Node* headNode, char* searchString, int chPoz)
{
	int ch = searchString[chPoz];
	if (headNode == NULL) return 0;
	if (ch == NULL)
	{
		return headNode->numberOfWords;
	}
	return SearchLetter(headNode->next[ch], searchString, chPoz + 1);
}

void Notebook::InsertLetter(Node* headNode, char* word, int chPoz)
{
	bool isEnd = false;
	int numberOfWords = 1;
	int ch = word[chPoz];
	if (ch == NULL)
	{
		if (headNode != NULL)
		{
			headNode->endWord = true;
		}
		return;
	}
	if (headNode == NULL)
	{
		headNode = new Node;
	}
	else
	{
		headNode->numberOfWords++;
	}
	InsertLetter(headNode->next[ch], word, chPoz + 1);
}


int Notebook::Search(char* searchString)
{
	return SearchLetter(head, searchString, 0);
}

void Notebook::Insert(char* newWord)
{
	InsertLetter(head, newWord, 0);
}

void Notebook::ShowUsage()
{
	cout << "Please enter the command in the following format: commandName [contactName]\n";
	cout << "possible values of commandName: Add, Find, Exit\n";
	cout << "contactName - string value (name of contact)\n";
}
