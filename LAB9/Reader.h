#pragma once
#include <fstream>
#include <string>
#include <vector>

class Reader
{
public:
	explicit Reader(const std::string &path);
	std::vector<short> readToTheEnd();
	void init(const std::string &path);
	int getItemsCount();
	~Reader();
private:
	int _dataItemsCount;
	std::ifstream _stream;
	std::vector<short> _data;
};

