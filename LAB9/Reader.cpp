#include "Reader.h"

Reader::Reader(std::string path) : _dataItemsCount(0), _stream(path)
{
	if (!this->_stream.is_open())
		throw std::invalid_argument("Invalid input path");

	std::string str;
	std::getline(this->_stream, str); // first line is number of input

	this->_dataItemsCount = std::stoi(str);
	this->_data.reserve(this->_dataItemsCount);
}

std::vector<int> Reader::readToTheEnd()
{
	std::string str;
	for (int i = 0; std::getline(this->_stream, str); i++)
	{
		int c = std::stoi(str);
		this->_data.push_back(c); // Converting to int
	}
	
	return this->_data;
}

int Reader::getItemsCount()
{
	return this->_dataItemsCount;
}

Reader::~Reader()
{
	this->_stream.close();
	if (this->_stream.is_open())
		throw std::invalid_argument("Error while closing file");
}