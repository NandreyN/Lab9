#include "Reader.h"
#include "limits.h"
Reader::Reader(const std::string &path) : _dataItemsCount(0), _stream(path)
{
	// Constructor 
	if (!this->_stream.is_open())
		throw std::invalid_argument("Invalid input path");

	std::string str; // declaring string
	std::getline(this->_stream, str); // first line is number of input is a number of data items

	this->_dataItemsCount = std::stoi(str); // getting int from std::string
	this->_data.reserve(this->_dataItemsCount); // reserving space in vector
}

std::vector<short> Reader::readToTheEnd()
{
	std::string str;
	for (int i = 0; std::getline(this->_stream, str); i++) // equal to : string != ""
	{
		short c = (short)std::stoi(str);

		this->_data.push_back(c); // Converting to int
	}
	
	return this->_data;
}

void Reader::init(const std::string &path)
{
	// For reading another file

	this->_stream.close();
	if (this->_stream.is_open())
		throw "Error while closing file";

	this->_stream.clear();
	
	this->_stream.open(path);

	std::string str;
	std::getline(this->_stream, str); // first line is number of input

	if (str == "")
		throw "File reading error";

	this->_dataItemsCount = std::stoi(str);
	this->_data.clear();
	this->_data.reserve(this->_dataItemsCount);
}

int Reader::getItemsCount()
{
	return this->_dataItemsCount;
}

Reader::~Reader()
{
	this->_stream.close();
	if (this->_stream.is_open())
		throw "Error while closing file";
}
