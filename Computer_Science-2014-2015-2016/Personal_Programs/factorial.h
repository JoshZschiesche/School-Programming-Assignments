//factorial function
#include<iostream>

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
