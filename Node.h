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

	Node(const char* key, unsigned char keyLen, const char* value, unsigned char valueLen) :
		key(key), keyLen(keyLen), value(value), valueLen(valueLen),
		left(NULL), right(NULL)
	{
	}

	~Node()
	{
		if (left) delete left;
		if (right) delete right;
	}
};
