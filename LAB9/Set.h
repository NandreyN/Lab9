#pragma once
#include <vector>
#include "Set255.h"

class Set:public Set255
{
public:
	explicit Set();
	explicit Set(std::vector<short> data);
	virtual ~Set();
	virtual int getType() override;
	std::vector<short> getItersactionWith(Set255& const another);
	bool isSubsetOf(Set255& const another);
};

