//Josh Zschiesche, 523000614, Jzschiesche1, jzschiesche1@tamu.edu

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
	try
	{
		srand (time(NULL));
		int ubound = 32;
		int lbound = 1;
		int guess = 0;
		int range = 1;
		int change = 0;
		int count = 0;
		int random_number = 16;
		string badNumber;
		vector<int> guesses;
		
		cout << "Enter a positive intiger upper bound" << endl << ">> ";
		
		bool correctInput = false;
		while(true)
		{
			cout << "Enter a positive intiger upper bound" << endl << ">> ";
			if(cin >> ubound)
			{
				if(ubound > 0)
				{
					break;
				}
				cout << "Value must be > 0, please try again.\n";
			}
			else
			{
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
		
		if(ubound == 1)
		{
			cout << "Yes!!" << endl;
			cout << "Guess is: 1" << endl;
			cout << "Number of tries = 1" << endl;
			return 0;
		}
		cout << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Upper Bound is:" << ubound << endl;
		
		correctInput = false;
		while(true)
		{
			cout << "Enter a positive intiger random number that is >= 1  but < upper bound to test " << endl << ">> ";
			if(cin >> random_number)
			{
				if(random_number >= 1 && random_number <= ubound)
				{
					break;
				}
				cout << "Enter in the correct input\n";
			}
			else
			{
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
		
		cout << "Random number to test is: " << random_number << endl;
		//cout << "Enter a positive Random number " << endl << ">> ";
		//cin >> random_number;
		
		while(random_number <= 0)
		{
			cout << "Random_Number was equal to zero, generating a new random number!" << endl;
			srand (time(NULL));
			random_number = rand()%ubound;
		}
		
		cout << "Random Number Between 1 and " << ubound << " generated" << endl;
		guess = ceil(ubound/2.0);
		
		cout << "Guess is: " << guess << endl;
		
		while (guess != random_number)
		{
			if (guess < random_number)
			{
				lbound = guess-1;
				cout << endl;
				cout << "Go Higher" << endl;
				++count;
				cout << "Number of tries = " << count << endl;
				range = ubound - lbound;
				change = ceil(range/2);
				guess = guess + change;
				cout << "Guess is: " << guess;
				//Makes it easier to read
				cout << endl;
				guesses.push_back(guess);
			}
			else if (guess > random_number)
			{
				ubound = guess+1;
				cout << endl;
				cout << "Go Lower" << endl;
				++count;
				cout << "Number of tries = " << count << endl;
				range = ubound - lbound;
				change = ceil(range/2);
				guess = guess - change;
				cout << "Guess is: " << guess;
				//Makes it easier to read
				cout << endl;
				guesses.push_back(guess);
			}
		}
		
		//Makes it easier to read	
		cout << endl;
		cout << "Yes!!" << endl;
		cout << "Number of tries = " << ++count << endl;
		cout << "The random number was: " << random_number;
	}
	catch(int e)
	{
		
	}
}