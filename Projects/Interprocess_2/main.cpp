//Interprocess app2 Created by Andrew Jonas 26/09/2021
#include<windows.h>
#include<iostream>

struct MyData
{
	int myint;
	float myfloat;
	char mychar;
	bool mybool;
	double mydouble;
};

int main()
{
	HANDLE fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");
	MyData* data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));
	data->myint = 54;
	//data->myfloat = 1.3214f;
	data->mychar = 'A';
	data->mybool = true;
	data->mydouble = 4.31164798;
	
	std::cout << "myint" << data->myint << std::endl;
	std::cout << "myfloat" << data->myfloat << std::endl;
	std::cout << "mychar" << data->mychar << std::endl;
	std::cout << "mybool" << data->mybool << std::endl;
	std::cout << "mydouble" << data->mydouble << std::endl;

	// unmap the memory block since we're done with it
	UnmapViewOfFile(data);

	CloseHandle(fileHandle);
	system("PAUSE");
}

