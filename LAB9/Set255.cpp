#include "Set255.h"
#include <limits.h>

Set255::Set255() : _maxVal(UCHAR_MAX), _bytesCount(_maxVal / 8) 
{
	// init variables above with UCHAR MAX and neede amount of bytes
	this->_bits = new unsigned char[this->_bytesCount + 1];

	for (int i = 0; i < this->_bytesCount; i++)
		this->_bits[i] = 0; // Initializing with Zero. if not to perform this, result is unpredictable
}

Set255::~Set255()
{
	delete[] this->_bits; // Basic constructor, destruction starts from basic to derived class
	this->_bits = nullptr; // to check in next classes
}

Set255::Set255(std::vector<short> data) : _maxVal(UCHAR_MAX), _bytesCount(_maxVal / 8)
{
	// Similar to the first constructor
	this->_bits = new unsigned char[this->_bytesCount + 1];
	for (int i = 0; i < this->_bytesCount; i++)
		this->_bits[i] = 0;

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] <= this->_maxVal) // checking if we are within the range
			this->add(data[i]); // if ok, perform adding
	}
}

Set255::Set255(int a)
{
	// Empty constructor for derived classes.
	// Not to re-initialize fields: maxVal & neededBytes
	// No memory troubles while allocation additional memory while old isn`t free in a correct way
}

int Set255::getType()
{
	// getting class type in integer format
	// is needed for performing polymorphism in other classes/main
	// is virtual
	return 0;
}

void Set255::add(short number)
{
	if (number > this->_maxVal) // range
		return;

	int numberOfByte = number / 8; // number of byte, where that number should be stored
	int position = number % 8; // position in that byte

	unsigned char a = 1; //000000000001, f.e.
	a <<= position; // it means that we move 1 "position" times left on 1 byte;

	this->_bits[numberOfByte] |= a; //  | see google.com)
}

void Set255::add(std::vector<short> data)
{
	for (int i = 0; i < data.size(); i++) // add all elemtns of vector 
		this->add(data[i]);
}

bool Set255::isInSet(short number)
{
	if (number > this->_maxVal) // range
		return false;

	int numberOfByte = number / 8;
	int position = number % 8;
	short p = 1;
	p <<= position;
	// checking value of a particular bit in appropriate char(byte) element
	if (this->_bits[numberOfByte] & p) // if NOT 0, it`s OK
		return true;

	return false;
}

void Set255::remove(short number)
{
	bool isThere = isInSet(number); // Firstly check, whether that element is present or not
	if (!isThere)
		return;

	int numberOfByte = number / 8;
	int position = number % 8;
	short p = 1;
	p <<= position;
	this->_bits[numberOfByte] ^= p; // Not to delete  the whole byte
}

std::vector<short> Set255::getNumberCollection()
{
	short p;
	std::vector<short> collectionToReturn;
	for (int i = 0; i < this->_bytesCount; i++) // going through all bytes
	{
		p = 1;
		for (int j = 0; j < 8; j++) // through bits
		{
			if (this->_bits[i] & p)
				collectionToReturn.push_back(i * 8 + j);

			p <<= 1;
		}
	}
	return collectionToReturn;
}