// DupCleaner.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <conio.h>

#include "InputLineStream.h"
#include "OutputLineStream.h"
#include "DupCleaner.h"

int _tmain(int argc, _TCHAR* argv[])
{
	InputLineStream input;
	OutputLineStream output;
	DupCleaner cleaner(input, output);
	cleaner.process();

	_getch();
	return 0;
}
