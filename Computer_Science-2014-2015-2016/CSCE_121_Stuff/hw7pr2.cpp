//Josh Zschiesche
//CSCE 121-502
//Due: Dec/08/2015
//hw7pr2.cpp

#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include "std_lib_facilities_4.h"

int main()
{
	string string_SSN;
	string si;
	cout << "Enter A Social Security Number: ";
	while (getline(cin,string_SSN))
	{
		regex pat1{R"(^\d{3}(s|-)?\d{2}(s|-)?\d{4}$)"};
		smatch matches;
		if (regex_search(string_SSN,matches,pat1))
		{
			regex pat2{R"(^(000)(s|-)?\d{2}(s|-)?\d{4}$)"};
			regex pat3{R"(^\d{3}(s|-)?(00)(s|-)?\d{4}$)"};
			regex pat4{R"(^\d{3}(s|-)?\d{2}(s|-)?(0000)$)"};
			regex pat5{R"(^(123)(s|-)?(45)(s|-)?(6789)$)"};
			regex pat6{R"(^(987)(s|-)?(65)(s|-)?(432\d)$)"};
			regex pat7{R"(^(666)(s|-)?\d{2}(s|-)?\d{4}$)"};
			regex pats9{R"(^(9\d{2})(s|-)?\d{2}(s|-)?\d{4}$)"};
			
			regex pat_num1{R"(^(042)(s|-)?(68)(s|-)?(4425)$)"};
			regex pat_num2{R"(^(078)(s|-)?(05)(s|-)?(1120)$)"};
			
			regex pat11{R"(^(111)(s|-)?(11)(s|-)?(1111)$)"};
			regex pat22{R"(^(222)(s|-)?(22)(s|-)?(2222)$)"};
			regex pat33{R"(^(333)(s|-)?(33)(s|-)?(3333)$)"};
			regex pat44{R"(^(444)(s|-)?(44)(s|-)?(4444)$)"};
			regex pat55{R"(^(555)(s|-)?(55)(s|-)?(5555)$)"};
			regex pat66{R"(^(666)(s|-)?(66)(s|-)?(6666)$)"};
			regex pat77{R"(^(777)(s|-)?(77)(s|-)?(7777)$)"};
			regex pat88{R"(^(888)(s|-)?(88)(s|-)?(8888)$)"};
			regex pat99{R"(^(999)(s|-)?(99)(s|-)?(9999)$)"};
			
			if (regex_search(string_SSN,matches,pat2))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n" << "\n";
			}
			else if (regex_search(string_SSN,matches,pat3))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat4))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat5))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat6))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat7))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat11))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat22))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat33))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat44))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat55))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat66))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat77))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat88))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat99))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat_num1))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pat_num2))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else if (regex_search(string_SSN,matches,pats9))
			{
				cout << "\n" << "Invalid Social Security Number" << "\n"<< "\n";
			}
			else
			{
				cout << "\n" << "Valid Social Security Number" << "\n"<< "\n";
			}
		}
		else
		{
			cout << "\n" << "Invalid Social Security Number" << "\n";
		}
		cout << "Enter A Social Security Number: ";
	}
}