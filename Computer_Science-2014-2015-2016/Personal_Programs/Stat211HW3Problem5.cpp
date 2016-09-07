#include <iostream>
#include <math.h>
#include <stdio.h>
//#include <factorial.h>

using namespace std;

long factorial(int n)
{
    int counter;
    long fact = 1;

     //for Loop Block
     for (int counter = 1; counter <= n; counter++)
     {
         fact = fact * counter;
     }

  return fact;
}

int main()
{
	double answer = 0;
	int lamda = 30;
	double e = 2.71828182845904523536;
	double prev_answer = 0;
	for(int i = 38; i <= 42; ++i)
	{
		answer = ((pow(e,(-1)*lamda))*pow(lamda,i))/factorial(i);
		answer += answer;
	}
	cout << "Answer is " << answer;
}