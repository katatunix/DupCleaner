#include "InputLineStream.h"
#include <string>

const char* data[] =
{
	//"value 1",
	//"key 1",

	//"value 2",
	//"key 2",

	//"value 3",
	//"key 3",

	//"value 3",
	//"key 3",

	//"value 3",
	//"key 3",

	//"value 3",
	//"key 4",

	//"value 1",
	//"key 1",

	//"value 1",
	//"key 5",

	"number1",
	"I am writing line1",
	"number2",
	"First line",
	"number3",
	"I am writing line2",
	"number4",
	"Second line",
	"number5",
	"I am writing line3",
	"number6",
	"Third line",
	"number7",
	"I am writing line2",
	"number8",
	"Fourth line",
	"number9",
	"I am writing line5",
	"number10",
	"Fifth line",
};

int idx = 0;
int numLine = sizeof(data) / sizeof(char*);

const char* InputLineStream::read(int& len)
{
	const char* line = data[idx++];
	len = strlen(line);
	return line;
}


bool InputLineStream::hasNext()
{
	return idx < numLine;
}
	
void InputLineStream::skipNext2Lines()
{
	idx += 2;
}
