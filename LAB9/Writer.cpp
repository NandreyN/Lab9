#include "Writer.h"

Writer::Writer(std::string path) : _stream(path)
{
	if (!this->_stream.is_open())
		throw std::invalid_argument("Invalid out file path");
}

void Writer::writeData(std::vector<int> data)
{
	for (int i=0;i<data.capacity();i++)
		this->_stream << data[i] << "\n";
}

Writer::~Writer()
{
	this->_stream.close();
	if (this->_stream.is_open())
		throw std::invalid_argument("cannot close out file");
}