#include "pch.h"
#include "Node.h"

const int NUMBER_ROUTS = 256;

Node::Node()
{
	numberOfWords = 1;
	isEnd = false;
	next = new Node*[NUMBER_ROUTS];
	for (int i = 0; i < NUMBER_ROUTS; i++) 
	{
		next[i] = NULL;
	}
};

void Node::setIsEnd(bool endWord)
{
	isEnd = endWord;
}

bool Node::getIsEnd()
{
	return isEnd;
}