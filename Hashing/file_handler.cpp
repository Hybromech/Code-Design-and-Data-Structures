#include "file_handler.h"

//string s_data;
//fh::fh(){}
string readFile(const char* filename)
{
	string s_line;
	string s_file;
	//Load in contents of texture file
	char file_data = 0;

	ifstream rf;
	//rf.open("./assets/test.dat");
	rf.open(filename);
	//rf.open("D:/Andrew/AIE/Diploma of Digital and Interactive Games/Subjects/Math for Games/Projects/Graphics Test Game/assets/Images/tank.png");
	if (!rf.is_open())//check if the file is open
	{
		cout << "File load error" << endl;
		exit(1);
	}

	//rf >> file_data;
	//cout << file_data;

	while (!rf.eof()) { // keep reading until end-of-file

		//cout << "The next number is " << file_data << endl;
		getline(rf, s_line);
		s_file += s_line;
		//cout << s_data << "\n";//print out the contents of the string
		//rf >> file_data; //read into file_data
		//rf >> s_data;
	}
	//cout << "Output " << s_data << endl;

	rf.close();
	return s_file;
	/*rf.read((char*)file_data, sizeof(file_data));
	rf.close();
	cout << file_data;*/
}


