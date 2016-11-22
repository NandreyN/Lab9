#pragma once
#include <vector>
class Set255 
{
public:
	explicit Set255();
	virtual ~Set255();
	explicit Set255(std::vector<short> data);
	explicit Set255(int a); // does nothing
	virtual int getType();

	void add(short number) ;
	void add(std::vector<short> data);
	bool isInSet(short number);
	void remove(short number);
	std::vector<short> getNumberCollection();
protected:
	unsigned char* _bits;
	int _maxVal;
	int _bytesCount;
};

