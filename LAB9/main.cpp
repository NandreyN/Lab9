#include <iostream>
#include "Reader.h"
#include "Writer.h"
#include "Set.h"
#include "Set255.h"
using namespace std;

int main()
{
	Reader reader("in.txt");
	Set255* set255 = new Set255(reader.readToTheEnd());


	reader.init("in2.txt");
	Set*  set = new Set(reader.readToTheEnd());

	Writer writer("out.txt");
	writer.writeLine("SET255:\n");
	writer.writeData(set255->getNumberCollection());

	delete set255;
	delete set;

	return 0;
}