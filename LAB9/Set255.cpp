#include "Set255.h"
#include <limits.h>

Set255::Set255() : _maxVal(UCHAR_MAX), _bytesCount(32)
{
	this->_bits = new unsigned char[this->_bytesCount];
	for (int i = 0; i < this->_bytesCount; i++)
		this->_bits[i] = 0;
}

Set255::~Set255()
{
	delete[] this->_bits;
}

Set255::Set255(std::vector<short> data) : _maxVal(UCHAR_MAX), _bytesCount(32)
{
	this->_bits = new unsigned char[this->_bytesCount];
	for (int i = 0; i < this->_bytesCount; i++)
		this->_bits[i] = 0;

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] <= this->_maxVal)
			this->add(data[i]);
	}
}

Set255::Set255(int a)
{
}

int Set255::getType()
{
	return 0;
}

void Set255::add(short number)
{
	if (number > this->_maxVal)
		return;

	int numberOfByte = number / 8;
	int position = number % 8;

	unsigned char a = 1;
	a <<= position; // -1 ?

	this->_bits[numberOfByte] |= a;
}

void Set255::add(std::vector<short> data)
{
	for (int i = 0; i < data.size(); i++)
		this->add(data[i]);
}

bool Set255::isInSet(short number)
{
	if (number > this->_maxVal)
		return false;

	int numberOfByte = number / 8;
	int position = number % 8;
	short p = 1;
	p <<= position;
	if (this->_bits[numberOfByte] & p)
		return true;
	return false;
}

void Set255::remove(short number)
{
	bool isThere = isInSet(number);
	if (!isThere)
		return;
	int numberOfByte = number / 8;
	int position = number % 8;
	short p = 1;
	p <<= position;
	this->_bits[numberOfByte] ^= p;
}

std::vector<short> Set255::getNumberCollection()
{
	short p;
	std::vector<short> collectionToReturn;
	for (int i = 0; i < this->_bytesCount; i++)
	{
		p = 1;
		for (int j = 0; j < 8; j++)
		{
			if (this->_bits[i] & p)
				collectionToReturn.push_back(i * 8 + j);

			p <<= 1;
		}
	}
	return collectionToReturn;
}