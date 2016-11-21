#include <iostream>
#include "Reader.h"
#include "Writer.h"
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
	return 0;
}