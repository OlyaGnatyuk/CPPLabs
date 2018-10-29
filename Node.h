#ifndef NODE_H
#define NODE_H

#include "stdafx.h"

const int NUMBER_ROUTS = 256;

class Node
{
private:
	bool isEnd;
public:
	Node();
	int numberOfWords;
	Node* next;
	void setIsEnd(bool endWord);
};

#endif