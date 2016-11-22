#include <iostream>
#include "Set.h"

Set::Set() : Set255(0)
{
	this->_maxVal = USHRT_MAX;
	this->_bytesCount = this->_maxVal / 8;

	this->_bits = new unsigned char[this->_bytesCount];
	for (int i = 0; i < this->_bytesCount; i++)
		this->_bits[i] = 0;
}

Set::Set(std::vector<short> data) : Set255(0)
{
	this->_maxVal = USHRT_MAX;
	this->_bytesCount = this->_maxVal / 8;

	this->_bits = new unsigned char[this->_bytesCount];
	for (int i = 0; i < this->_bytesCount; i++)
		this->_bits[i] = 0;

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] <= this->_maxVal)
			this->add(data[i]);
	}
}

Set::~Set()
{
	delete[] this->_bits;
}

int Set::getType()
{
	return 1;
}

std::vector<short> Set::getItersactionWith(Set255& another)
{
	auto collectionThis = this->getNumberCollection();
	auto collectionAnother = another.getNumberCollection();

	std::vector<short> toReturn;
	for (int i = 0; i < collectionThis.size();i++)
		if (std::find(collectionAnother.begin(), collectionAnother.end(), collectionThis[i]) != collectionAnother.end())
		{
			toReturn.push_back(collectionThis[i]);
		}
	return toReturn;
}

bool Set::isSubsetOf(Set255& another)
{
	auto dataThis = this->getNumberCollection();
	for (int i =0;i<dataThis.size();i++)
	{
		if (!another.isInSet(dataThis[i]))
			return false;
	}
	return true;
}