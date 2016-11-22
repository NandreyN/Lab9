#include <iostream>
#include "Reader.h"
#include "Writer.h"
#include "Keeper.h"
using namespace std;

int main()
{
	Reader reader("in.txt");
	int len = reader.getItemsCount();

	Keeper keep(reader.readToTheEnd());

	Writer writer("out.txt");
	auto var = keep.getNumberCollection();

	writer.writeData(var);

	return 0;
}