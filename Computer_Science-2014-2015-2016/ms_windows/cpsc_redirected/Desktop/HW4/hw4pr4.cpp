//Josh Zschiesche
//CSCE 121-502
//Due: October 8,2015
//hw4pr4.cpp


#include "Chrono.h"
int main()
{
    try
    {
        Chrono::Date d1;
        Chrono::Date d2;
        Chrono::Date d3;
        while(cin >> d1)
        {
            cout << "Enter a (yy.mm.dd)\n";
            d2 = d1;
            d3 = d1++;
            if(d2 != d3)error("error in postfix ++");
            if(d2 == d1)error("error in postfix ++");
            if(d1 != ++d2)error("error in postfix ++");
            cout << "Tomorrow is" << d1 << '\n';
        }
    catch(Chrono::Date::Invalid)
    {
        cerr << "Not a valid date\n";
        return 1;
    }
}

