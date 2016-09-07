//Josh Zschiesche
//Date: Feb-12-2016
#include <iostream>
#include <iterator>
#include <ctime>
#include <cstdio>
#include <fstream>

using namespace std;

int main()
{
	//Declare variables
	string file_name = "";
	int random_x = 1;
	int count = 1;

	//Get file name
	cout << "Enter In a File Name" << endl << ">> " << endl;
	cin >> file_name;

	//start the out streams to save to file
	ofstream to_file(file_name);
	
	//random number seed
	srand (time(NULL));
	
	//get how many numbers to make
	cout << "How many numbers should we make?" << endl << ">> ";
	cin >> count;
	
	for (int t=0; t < count; ++t)
	{
		random_x = rand();
		
		//put the random numbers in files
		to_file << random_x << endl;
	}
	
	to_file.close();
}	