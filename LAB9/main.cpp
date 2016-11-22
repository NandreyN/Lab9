#include <iostream>
#include "Reader.h"
#include "Writer.h"
#include "Set.h"
#include "Set255.h"
using namespace std;

int main()
{
	Reader reader("in.txt");
	Set255 keep(reader.readToTheEnd());

	reader.init("in2.txt");
	Set set(reader.readToTheEnd());

	auto in = set.getItersactionWith(keep);
	bool f = set.isSubsetOf(set);

	return 0;
}