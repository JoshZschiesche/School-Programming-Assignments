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
	int ubound;
	int guess = 0;
	int range;
	int change;
	int count = 0;
	int random_number;
	
	cout << "Enter a positive intiger upper bound" << endl;
	cin >> ubound;
	
	while(ubound <=0)
	{
		cout << "Enter A positive Number" << endl;
		cin >> ubound;
	}
	
	random_number = rand()%ubound;
	
	while(random_number <= 0)
	{
		cout << "Random_Number was equal to zero, generating a new random number!" << endl;
		srand (time(NULL));
		random_number = rand()%ubound;
	}
	
	//cout << "Random Number Generated is: " << random_number << endl;
	cout << "Random Number Between 1 and " << ubound << " generated" << endl;
	
	cout << "Enter A new guess" << endl;
	cin >> guess;
	
	while (guess != random_number)
	{
		if (guess < random_number)
		{
			cout << endl;
			cout << "Go Higher" << endl;
			++count;
			cout << "Number of tries = " << count << endl << endl;
			
			//Makes it easier to read
			cout << endl;
		}
		else if (guess > random_number)
		{
			cout << endl;
			cout << "Go Lower" << endl;
			++count;
			cout << "Number of tries = " << count << endl << endl;
			
			//Makes it easier to read
			cout << endl;
		}
		
		cout << "Enter A new guess" << endl;
		cin >> guess;
	}
	
	//Makes it easier to read	
	cout << endl << endl << "Enter a new guess" << endl;
	cout << "Yes!!" << endl;
	cout << "Number of tries = " << ++count << endl;
}