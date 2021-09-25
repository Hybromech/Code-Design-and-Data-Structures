///Hash Table Written by Andrew Jonas 20/09/2021

#include "file_handler.h"
#include <vector>
//Forward declare functions
unsigned int Hash(string data, unsigned int length);
void Insert(string data, int length);

const int tableSize = 100;
string data_arr[tableSize];

int main()
{
	//change to relative paths
	string data1 = readFile("../Files/test.dat");
	string data2 = readFile("../Files/test1.dat");
	string data3 = readFile("../Files/test2.dat");
	string data4 = readFile("../Files/test3.dat");
	string data5 = readFile("../Files/test4.dat");

	Insert(data1, data1.length());
	Insert(data1, data1.length());
	Insert(data2, data2.length());
	Insert(data3, data3.length());
	Insert(data4, data4.length());
	Insert(data5, data5.length());
}
unsigned int Hash(string data, unsigned int length)
{
	unsigned int hash = 0;
	for (unsigned int i = 0;  i < length; i++)
	{
		hash += length / 2.1298374309;
		hash += data[i] << 3;
	
		return hash;
	}
}

void Insert(string data,int length)
{
	unsigned int hashedKey = Hash(data, length);

	hashedKey = hashedKey % tableSize;

	std::cout << "hasedKey is " << hashedKey << std::endl;

	if (data_arr[hashedKey][0] == NULL)//check for collision
	{
		data_arr[hashedKey] = data;//insert new data
		std::cout << "data in " << hashedKey << " is \n" << data_arr[hashedKey] << std::endl;
	}
	else std::cout << "Collision found" << std::endl;
}



