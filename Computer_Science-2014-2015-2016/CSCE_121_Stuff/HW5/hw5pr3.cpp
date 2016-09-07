#include "std_lib_facilities_4.h"
int main()
{
	cout << "Name two input files and an output file\n";
	
	string file;
	
	ifstream in1, in2;
	ofstream out;
	
	//read in and open streams
	cout << "First input file\n";
	cin >> file;
	
	in1.open(file);
	
	cout << "Second input file\n";
	cin >> file;
	
	in2.open(file);
	
	cout << "The output file\n";
	cin >> file;
	
	out.open(file);
	
	int line = 1;
	while(not in1.eof() and not in2.eof())
	{
		string a, b;
		getline(in1, a);
		getline(in2, b);
		
		out << line++ << ':';
		if(a == b)
		{
			out << "OK\n";
		}
		else
		{
			out << "DIFF\n";
		}
	}
	if(in1.eof() and !in2.eof())
	{
		//extra lines in in2
		string a;
		getline(in2, a);
		out << line++ << ":DIFF\n";
	}
	if(in2.eof() and !in1.eof())
	{
		//extra lines in in1
		string a;
		getline(in1, a);
		out << line++ << ":DIFF\n";
	}
}
