#include "OutputLineStream.h"
#include <stdio.h>

void OutputLineStream::write(const char* line, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%c", line[i]);
	}
	printf("\n");
}
