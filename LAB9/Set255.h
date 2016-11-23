#pragma once
#include <vector>
class Set255 
{
public:
	explicit Set255(); // Constructor with no params
	virtual ~Set255();
	explicit Set255(const std::vector<short> &data); // Init with a data set
	explicit Set255(int a); // does nothing
	virtual int getType(); // getting type, polimorphic method

	void add(short number) ; // do not need to virtualize, because works pretty identical for both methods, depending on _maxVal and _bytesCount 
	void add(const std::vector<short> data); // the same
	bool isInSet(short number); // same
	void remove(short number); // same
	std::vector<short> getNumberCollection(); // same
protected:
	unsigned char* _bits; // data itself
	int _maxVal; // max value, that can be stored in that class
	int _bytesCount; // bytes which are needed for storing exactly maxVal
};

