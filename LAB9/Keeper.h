#pragma once
class Keeper
{
public:
	explicit Keeper(int range);
	virtual ~Keeper();
	virtual void add(int number);
	bool isInSet(int number);
	void remove(int number);
protected:
	char* _bits;
	int _bytesCount;
	char getBit(int number); // << number
};

