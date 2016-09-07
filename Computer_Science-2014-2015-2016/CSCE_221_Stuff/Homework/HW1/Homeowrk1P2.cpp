//Josh Zschiesche, 523000614, Jzschiesche1, jzschiesche1@tamu.edu

#include <string>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <cstdlib>
using namespace std;

int main()
{
	string word = "";
	cout << "Enter ||| to exit the program!" << endl;
	while(word != "|||")
	{
		cout << "Please enter a string" << endl << ">> ";
		cin >> word;
		transform(word.begin(), word.end(), word.begin(), ::toupper);
		if(equal(word.begin(),word.begin() + word.size()/2, word.rbegin()))
		{
			cout << "That was a palindrome.\n";
		}
		else
		{
			cout << "This is NOT a palindrome.\n";
		}
	}
	cout << "Done" << endl;
}