#pragma once
#include <vector>

class Keeper
{
public:
	Keeper();
	virtual ~Keeper();
	virtual void add(short number); // to handle negative numbers:  1 - negative, 0 - positive.  
	bool isInSet(short number);
	void remove(short number);
	std::vector<short> getNumberCollection();
protected:
	char* _bits;
	char* _buffer;
	int _bytesCount;
	short _max;
	void getByteBuff(short number); // << number
};

