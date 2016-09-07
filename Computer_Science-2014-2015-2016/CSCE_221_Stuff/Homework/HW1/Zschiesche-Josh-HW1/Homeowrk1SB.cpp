//Josh Zschiesche, 523000614, Jzschiesche1, jzschiesche1@tamu.edu

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ostream>
#include <math.h>

using namespace std;

int main()
{
	srand (time(NULL));
	int ubound = 32;
	int lbound = 1;
	int guess = 0;
	int range = 1;
	int change = 0;
	int count = 0;
	int random_number = 16;
	
	cout << "Enter a positive intiger upper bound" << endl;
	
	for(int i = 0; pow(2,i) < 512; ++i)
	{
		ubound = 32;
		lbound = 1;
		guess = 0;
		range = 1;
		change = 0;
		count = 0;
		random_number = 16;
		
		ubound = pow(2,i);
		
		cout << "Upper Bound is: " << ubound << endl;
		
		random_number = rand()%ubound+1;
	
		cout << "Random Number Between 1 and " << ubound << " generated" << endl;
		guess = ceil(ubound/2.0);
	
		while (guess != random_number)
		{	
			//cout << "GUESS: "<<guess<<" RAND: "<< random_number <<endl;
			if (guess < random_number)
			{
				lbound = guess;
				cout << endl;
				cout << "Go Higher" << endl;
				++count;
				cout << "Number of tries = " << count << endl;
				range = ubound - lbound;
				change = ceil(range/2.0);
				guess = guess + change;
				cout << "Guess is: " << guess;
				//Makes it easier to read
				cout << endl;
			}
			else if (guess > random_number)
			{
				ubound = guess;
				cout << endl;
				cout << "Go Lower" << endl;
				++count;
				cout << "Number of tries = " << count << endl;
				range = ubound - lbound;
				cout <<"NEW RANGE: " << range<<endl;
				change = ceil(range/2.0);
				guess = guess - change;
				cout << "Guess is: " << guess;
				//Makes it easier to read
				cout << endl;
			}
			
			//cin>> count;
		}
		//Makes it easier to read	
		cout << endl;
		cout << "Yes!!" << endl;
		cout << "Number of tries = " << ++count << endl;
		cout << "The random number was: " << random_number;
		}
	}
