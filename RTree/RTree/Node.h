#ifndef NODE_H
#define NODE_H

class Node
{
private:
	bool isEnd;
public:
	Node();
	int numberOfWords;
	Node** next;
	bool getIsEnd();
	void setIsEnd(bool endWord);
};

#endif