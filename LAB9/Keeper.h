#pragma once
#include <vector>

class Keeper
{
public:
	Keeper();
	explicit Keeper(std::vector<short> data);
	virtual ~Keeper(); 

	/// TO DO FROM FILE!!!!
	virtual void add(short number); // to handle negative numbers:  1 - negative, 0 - positive.  
	virtual void add(std::vector<short> data);
	static Keeper ifIntersect( Keeper& const setOne, Keeper& const setTwo);
	bool isIncludedInto(Keeper& const another);
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

