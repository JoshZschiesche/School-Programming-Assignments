//Josh Zschiesche
//CSCE 121-502
//Due: Dec/08/2015
//hw7pr1.cpp

#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include "std_lib_facilities_4.h"

int main()
{
	string string_ISBN;
	cout << "Enter An ISBN: ";
	while (getline(cin,string_ISBN))
	{
		regex pat {R"(^(978)|(979)((\s|-)?(\d)){9}(\s|-)?(\d|X)$)"};//regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"};
		smatch matches;
		if (regex_search(string_ISBN,matches,pat))
		{
			cout << "\n" <<"Valid ISBN" << "\n";
		}
		else
		{
			cout <<"\n" << "Invalid ISBN" << "\n";
		}
		cout << "Enter An ISBN: ";
	}
	cout << "DONE '|' was entered" << "\n";
}