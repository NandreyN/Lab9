#include <iostream>
#include "Reader.h"
#include "Writer.h"
#include "Set.h"
using namespace std;

int main()
{
	Reader reader("in.txt");
	Set keep(reader.readToTheEnd());

	reader.init("in2.txt");
	Set set(reader.readToTheEnd());
	
	return 0;
}