#include "Keeper.h"
#include <iostream>
#include <limits.h>

Keeper::Keeper()
{
	this->_max = 32767;
	this->_bytesCount = ceil(this->_max / 8); // Defining the amount of bytes we need

	this->_bits = new char[this->_bytesCount];

	for (int i = 0; i < this->_bytesCount; i++)
		this->_bits[i] = 0; // Init with 0
	this->_buffer = nullptr;
	
	// I need _buffer to pass data between methods, because number can be large enough
	// to be placed into one byte;
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