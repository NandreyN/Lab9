#pragma once
#include <string>
#include <fstream>
#include <vector>

class Writer
{
public:
	Writer(std::string path);
	void writeData(std::vector<int> data);
	~Writer();
private:
	std::ofstream _stream;
};

