#include <iostream>
#include "Reader.h"
#include "Writer.h"
#include "Keeper.h"
using namespace std;

int main()
{
	Reader reader("in.txt");
	int len = reader.getItemsCount();
	
	vector<int> data;
	data = reader.readToTheEnd();

	for (int i = 0; i < len; i++)
		cout << data[i] << " ";

	cout << endl;
	
	Writer writer("out.txt");
	writer.writeData(data);

	Keeper k;
	auto a = k.getNumberCollection();
	return 0;
}