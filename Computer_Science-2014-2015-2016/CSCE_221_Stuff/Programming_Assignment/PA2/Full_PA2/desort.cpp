#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm> // for std::copy
#include <string>

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
	
	for (int t=count; t >= 0; t--)
	{
		random_x = t;
		
		//put the random numbers in files
		to_file << random_x << endl;
	}
	
	to_file.close();
}