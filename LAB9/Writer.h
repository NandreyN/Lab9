#pragma once
#include <string>
#include <fstream>
#include <vector>

class Writer
{
public:
	Writer(std::string path);
	void writeData(std::vector<short> &data);
	~Writer();
private:
	std::ofstream _stream;
};

