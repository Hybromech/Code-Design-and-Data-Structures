//Interprocess app1 Created by Andrew Jonas 26/09/2021
#include <windows.h>
#include <iostream>
struct MyData{
	MyData()
	{
		myfloat = 77;
	}
	int myint;
	float myfloat;
	char mychar;
	bool mybool;
	double mydouble;
};

int main()
{
// IN APPLICATION 1 – The host of the named shared memory
// open a named shared memory block
	MyData myData = MyData();
	//std::cout << myData->myfloat;
	
	HANDLE fileHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
		nullptr, // optional security attributes
		PAGE_READWRITE, // read/write access control
		0, sizeof(MyData), // size of the memory block,
		L"MySharedMemory");
	
	
	MyData* data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));//not sure what the green error means.
	
	*data = myData;
	
	std::cout << data->myfloat;

	system("PAUSE");
	
	CloseHandle(fileHandle);
}