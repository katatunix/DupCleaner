#include "DupCleaner.h"

#include <stdio.h>

DupCleaner::DupCleaner(InputLineStream& inStream, OutputLineStream& outStream) :
	m_inStream(inStream), m_outStream(outStream),
	m_treeHead(NULL)
{
}

DupCleaner::~DupCleaner()
{
	treeDelete();
}

void DupCleaner::process()
{
	treeDelete();

	while (m_inStream.hasNext())
	{
		int valueLen;
		const char* value = m_inStream.read(valueLen);
		int keyLen;
		const char* key = m_inStream.read(keyLen);

		bool isNewItem = treeFindAndInsert(key, keyLen, value, valueLen);
		if (isNewItem)
		{
			m_outStream.write(value, valueLen);
			m_outStream.write(key, keyLen);
		}
		else
		{
			m_inStream.skipNext2Lines();
		}
	}
}

void DupCleaner::treeDelete()
{
	if (m_treeHead)
	{
		delete m_treeHead;
		m_treeHead = NULL;
	}
}

bool DupCleaner::treeFindAndInsert(const char* key, int keyLen, const char*value, int valueLen)
{
	if (!m_treeHead)
	{
		m_treeHead = new Node();
		m_treeHead->key = key;
		m_treeHead->keyLen = keyLen;
		m_treeHead->value = value;
		m_treeHead->valueLen = valueLen;
		return true;
	}
	
	Node* node = m_treeHead;
	Node* dad = NULL;
	char cmp = 0;
	do
	{
		cmp = compare(key, keyLen, node->key, node->keyLen);
		if (cmp == 0)
		{
			return false; // found
		}
		dad = node;
		if (cmp < 0)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
	while (node);

	node = new Node();
	node->key = key; node->keyLen = keyLen;
	node->value = value; node->valueLen = valueLen;

	if (cmp < 0)
	{
		dad->left = node;
	}
	else
	{
		dad->right = node;
	}

	return true; // a new node has been inserted
}

char DupCleaner::compare(const char* key1, int len1, const char* key2, int len2)
{
	int minLen = len1 < len2 ? len1 : len2;
	for (int i = 0; i < minLen; i++)
	{
		if (key1[i] < key2[i]) return -1;
		if (key1[i] > key2[i]) return 1;
	}
	
	if (len1 < len2) return -1;
	if (len1 > len2) return 1;
	return 0;
}
