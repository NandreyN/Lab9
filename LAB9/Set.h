#pragma once
#include <vector>

class Set
{
public:
	Set();
	explicit Set(std::vector<short> data);
	virtual ~Set(); 
	virtual int getType();
	virtual void add(short number); // to handle negative numbers:  1 - negative, 0 - positive.  
	virtual void add(std::vector<short> data);
	static std::vector<short> intersection( Set& const setOne, Set& const setTwo);
	bool isSubsetOf(Set& const another);
	virtual bool isInSet(short number);
	virtual void remove(short number);
	virtual std::vector<short> getNumberCollection();
protected:
	char* _bits;
	char* _buffer;
	int _bytesCount;
	short _max;
	void setByteBuff(short number); // << number
	virtual void processQueue();
	std::vector<short> _queue;
};

