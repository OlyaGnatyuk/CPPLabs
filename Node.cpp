#include "Node.h"

Node::Node()
{
	next = new Node[NUMBER_ROUTS];
	for (int i = 0; i < NUMBER_ROUTS; i++) 
		next[i] = NULL;
};

void Node::setIsEnd(bool endWord)
{
	isEnd = endWord;
}