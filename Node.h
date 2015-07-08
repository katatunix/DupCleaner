#pragma once

#include <stdio.h>

class Node
{
public:
	const char* key;
	unsigned char keyLen;
	const char* value;
	unsigned char valueLen;

	Node* left;
	Node* right;

	Node() : left(NULL), right(NULL), key(NULL), keyLen(0), value(NULL), valueLen(0)
	{
	}

	~Node()
	{
		if (left) delete left;
		if (right) delete right;
	}
};
