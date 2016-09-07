#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;
///////////////////////////////////////////////////////////////Functions/Classes////////////////////////////////////////////////////////////////////////////////////
struct record
{
	int grade;
	int uin;
	string e_mail;
	string name;
};
struct uin_grade
{
	int uin;
	int grade;
};
int hashingFunction(int uin, int size_table)
{
	return uin%size_table;
}
//////////////////////////////////////////////////////////////////////MAIN/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	ifstream file ("input.csv");
	string value;
	record input;
	
	vector<record> vec;
	while ( getline ( file, input.name, ',' ) )
	{
		string uin_string;
		string grade_string;
		
		getline ( file, input.e_mail, ',' );
		
		getline ( file, uin_string, ',' );
		input.uin = atoi(uin_string.c_str());
		
		getline ( file, grade_string );
		input.grade = atoi(grade_string.c_str());
		
		cout << "Input.grade is:" << input.name << ", " << input.e_mail << ", " << uin_string << ", " << grade_string << endl;
		vec.push_back(input);
	}
	
	uin_grade ar[200]; // this is the hash table
	for(auto foo:vec)
	{
		uin_grade& bar = ar[hashingFunction(foo.uin, 200)];
		bar.uin = foo.uin;
		bar.grade = foo.grade;
	}
	
	ifstream file2 ("roster.csv");
	string str;
	record roster;
	
	vector<record> vec2;
	while (getline(file2, roster.name, ','))
	{
		string uin_string;
		string grade_string;
		
		getline ( file2, roster.e_mail, ',' );
		
		getline ( file2, uin_string, ',' );
		roster.uin = atoi(uin_string.c_str());
	
		roster.grade = -1;
		
		vec2.push_back(roster);
	}
	
	for(auto& foo:vec2)
	{
		uin_grade& bar = ar[hashingFunction(foo.uin, 200)];
		if (bar.grade > 0 && bar.grade <= 100)
		{
			foo.grade = bar.grade;
		}
	}
	
	ofstream out ("Output.csv");
	for(auto foo:vec2)
	{
		if (foo.grade == -1)
		{
			out << foo.name << "," << foo.e_mail << "," << foo.uin;
			out << endl;
		}
		else
		{
			out << foo.name << "," << foo.e_mail << "," << foo.uin << "," << foo.grade;
			out << endl;
		}
	}
}