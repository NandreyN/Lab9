#include <iostream>
#include "Set.h"

Set::Set() : Set255(0)
{
	this->_maxVal = USHRT_MAX;
	this->_bytesCount = this->_maxVal / 8;
	// new ranges

	this->_bits = new unsigned char[this->_bytesCount + 1];
	for (int i = 0; i < this->_bytesCount; i++)
		this->_bits[i] = 0;

	// calling Set255(0) , an empty one, in order to not to overwrite range settings
}

Set::Set(const std::vector<short> &data) : Set255(0)
{
	// The same situation as above

	this->_maxVal = USHRT_MAX;
	this->_bytesCount = this->_maxVal / 8;

	this->_bits = new unsigned char[this->_bytesCount + 1];
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
	// Memory will be released in Base class destructor
	// Because it is virtual
	// If it`s not, base destructor won`t be called

	if (this->_bits != nullptr)
		delete[] this->_bits;
	this->_bits = nullptr;
}

int Set::getType()
{
	return 1; // Class type
}

std::vector<short> Set::getItersactionWith(Set255& another)
{
	// Getting the collection of elements, which belong to both sets

	if (this == &another) // do not need to perform operation in case of address identity
		return this->getNumberCollection();

	auto collectionThis = this->getNumberCollection(); // getting item collection of this class
	auto collectionAnother = another.getNumberCollection(); // of parameter class

	std::vector<short> toReturn; // empty vector to store that elements

	for (int i = 0; i < collectionThis.size(); i++)
		if (std::find(collectionAnother.begin(), collectionAnother.end(),
			collectionThis[i]) != collectionAnother.end()) // function to find: std::find(vect.begin(), vector.end(), whatToSearch) != vect.end(), which means that the elemtn
															// is present in collection
		{
			toReturn.push_back(collectionThis[i]);
		}
	return toReturn;
}

bool Set::isSubsetOf(Set255& another)
{
	if (this == &another) // do not need to perform operation in case of address identity
		return true;

	auto dataThis = this->getNumberCollection(); // Getting collection of current set

	for (int i = 0; i < dataThis.size(); i++)
	{
		if (!another.isInSet(dataThis[i])) // Checking if each element of current collection excists in parameter`s class collection
			return false; // if not , curent class is not a subset of another
	}
	return true;
}