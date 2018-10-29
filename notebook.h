#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include "stdafx.h"
#include "Node.h"

class Notebook
{
private:
	Node* head;
	void InsertLetter(Node** headNode, char* word, int chPoz);
	int  SearchLetter(Node* headNode, char* searchString, int chPoz);
public:
	Notebook();
	void Insert(char* newWord);
	int  Search(char* searchString);
	static void ShowUsage();
};

#endif