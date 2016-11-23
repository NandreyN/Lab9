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
	writer.writeLine("SET255:");
	writer.writeData(set255->getNumberCollection());
	writer.writeLine("\nSET");
	writer.writeData(set->getNumberCollection());

	writer.writeLine("\nIntersaction:");
	writer.writeData(set->getItersactionWith(*set255));

	writer.writeLine("\nIs set255 a subset of Set:");
	bool res = set->isSubsetOf(*set255);
	string message = "false";
	if (res)
		message = "true";
	writer.writeLine(message);

	delete set255;
	delete set;

	return 0;
}