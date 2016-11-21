#pragma once
#include <fstream>
#include <string>
#include <vector>

class Reader
{
public:
	explicit Reader(std::string path);
	std::vector<short> readToTheEnd();
	int getItemsCount();
	~Reader();
private:
	int _dataItemsCount;
	std::ifstream _stream;
	std::vector<short> _data;
};

