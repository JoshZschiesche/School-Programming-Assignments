//Josh Zschiesche
//CSCE 121-502
//Due: October 8,2015
//hw4pr3.cpp


#include "Chrono.h"
#include "std_lib_facilities_4.h"

int main()
{
    try
    {
        Chrono::Date date1;
        cout << "Enter a date (yy.mm.dd)\n";
        while (cin >> date1)
        {
            cout << "Tomorrow is: " << ++date1 << "\n" << "Enter a date (yy.mm.dd)\n";
        }
    }
    catch (Chrono::Date::Invalid)
    {
        cerr << "Not valid date\n";
        return 1;
    }
}
