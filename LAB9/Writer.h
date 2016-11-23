#pragma once
#include <string>
#include <fstream>
#include <vector>

class Writer
{
public:
	Writer(std::string path);
	void writeData(const std::vector<short> &data);
	void writeLine(const std::string line);
	~Writer();
private:
	std::ofstream _stream;
};

