#include "Keeper.h"
#include <iostream>
#include <limits.h>

Keeper::Keeper() : _max()
{
	this->_bytesCount = static_cast<int>(ceil(this->_max / 8)); // Defining the amount of bytes we need
	this->_queue;
	this->_bits = new char[this->_bytesCount];

	for (int i = 0; i < this->_bytesCount; i++)
		this->_bits[i] = 0; // Init with 0
	this->_buffer = nullptr;
	this->_queue;
	// I need _buffer to pass data between methods, because number can be large enough
	// to be placed into one byte;
}

Keeper::Keeper(std::vector<short> data) : _max(32767)
{
	this->_bytesCount = static_cast<int>(ceil(this->_max / 8));
	this->_bits = new char[this->_bytesCount];
	this->_buffer = nullptr;
	for (int i = 0; i < this->_bytesCount; i++)
		this->_bits[i] = 0; // Init with 0

	if (data.capacity() >= static_cast<size_t>(this->_max))
		throw "Overflow";

	this->_queue = data;
	this->processQueue(); // !!!!!!!!!!!!!!!!!!!!!!!!!!!
}

Keeper::~Keeper()
{
	try
	{
		delete[] this->_bits; // can point to the memory area, which has been actually released
	}
	catch (...)
	{
		std::cout << "Exception in ~Keeper" << std::endl;
	}
	if (this->_buffer != nullptr)
		delete[] this->_buffer;
}

void Keeper::processQueue()
{
	for (int i = 0; i < this->_queue.size(); i++)
		this->add(this->_queue[i]);

	this->_queue.clear();
}

void Keeper::add(short number)
{
	this->setByteBuff(number);

	for (int i = 0; i < this->_bytesCount; i++)
		if (this->_buffer[i] != 0)
		{
			this->_bits[i] |= this->_buffer[i];
			this->_buffer[i] = 0;
		}
}

void Keeper::add(std::vector<short> data)
{
	this->_queue = data;
	this->processQueue();
}

std::vector<short> Keeper::ifIntersect(Keeper& setOne, Keeper& setTwo)
{
	auto collectionOne = setOne.getNumberCollection();
	auto collectionTwo = setTwo.getNumberCollection();
	std::vector<short> data;

	for (int i = 0; i < collectionTwo.size(); i++)
		if (std::find(collectionOne.begin(), collectionOne.end(), collectionTwo[i]) != collectionOne.end())
		{
			data.push_back(collectionTwo[i]);
		}

	return data;
}

bool Keeper::isSubsetOf(Keeper& another)
{
	auto thisNumberCollection = this->getNumberCollection();

	for (int i = 0; i < thisNumberCollection.size(); i++)
	{
		if (!another.isInSet(thisNumberCollection[i]))
			return false;
	}
	return true;
}

bool Keeper::isInSet(short number)
{
	int numberOfByte = number / 8;
	int position = number % 8;
	short p = 1;
	p <<= position;
	if (this->_bits[numberOfByte] & p)
		return true;
	return false;
}

void Keeper::remove(short number)
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

std::vector<short> Keeper::getNumberCollection()
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


void Keeper::setByteBuff(short number)
{
	if (this->_buffer == nullptr)
		this->_buffer = new char[this->_bytesCount];

	for (int i = 0; i < this->_bytesCount; i++)
		this->_buffer[i] = 0;

	// Finding the eldest bit in number;

	int numberOfByte = number / 8;
	int position = number % 8;

	char a = 1;
	a <<= position; // -1 ?

	this->_buffer[numberOfByte] = a;
}