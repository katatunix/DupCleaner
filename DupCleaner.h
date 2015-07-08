#pragma once

#include "InputLineStream.h"
#include "OutputLineStream.h"

#include "Node.h"

class DupCleaner
{
public:
	DupCleaner(InputLineStream& inStream, OutputLineStream& outStream);
	~DupCleaner();

	void process();

private:
	InputLineStream& m_inStream;
	OutputLineStream& m_outStream;

	Node* m_treeHead;

	void treeDelete();
	bool treeFindAndInsert(const char* key, int keyLen, const char*value, int valueLen);

	char compare(const char* key1, int len1, const char* key2, int len2);
};
