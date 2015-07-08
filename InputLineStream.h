#pragma once

class InputLineStream
{
public:
	const char* read(int& len);
	bool hasNext();
	void skipNext2Lines();
};
