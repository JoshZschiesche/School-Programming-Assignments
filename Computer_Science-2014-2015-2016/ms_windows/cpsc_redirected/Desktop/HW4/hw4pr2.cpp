//Josh Zschiesche
//CSCE 121-502
//Due: October 8,2015
//hw4pr2.cpp

#include "randint.h"
#include "std_lib_facilities_4.h"
int main()
{
        int num0 = 0;
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        int num4 = 0;
        int num5 = 0;
        int num6 = 0;
        int num7 = 0;
        int num8 = 0;
        int num9 = 0;

    for (int i = 0; i <= 1000000; ++i)
    {
        int random = randint();
        int last_rand_char = random%10; 

        switch (last_rand_char)
        {
            case 0:
                {
                    ++num0;
                    break;
                }
            case 1:
                {
                    ++num1;
                    break;
                }
            case 2:
                {
                    ++num2;
                    break;
                }
            case 3:
                {
                    ++num3;
                    break;
                }
            case 4:
                {
                    ++num4;
                    break;
                }
            case 5:
                {
                    ++num5;
                    break;
                }
            case 6:
                {
                    ++num6;
                    break;
                }
            case 7:
                {
                    ++num7;
                    break;
                }
            case 8:
                {
                    ++num8;
                    break;
                }
            case 9:
                {
                    ++num9;
                    break;
                }
    }
    }
    cout << setw(7) << left << "Digit" << setw(15) << left << "Frequency" << "\n";
    cout << setw(7) << "0" << setw(15) << num0 << string(num0 / 2000, '*') << "\n";
    cout << setw(7) << "1" << setw(15) << num1 << string(num1 / 2000, '*') << "\n";
    cout << setw(7) << "2" << setw(15) << num2 << string(num2 / 2000, '*') << "\n";
    cout << setw(7) << "3" << setw(15) << num3 << string(num3 / 2000, '*') << "\n";
    cout << setw(7) << "4" << setw(15) << num4 << string(num4 / 2000, '*') << "\n";
    cout << setw(7) << "5" << setw(15) << num5 << string(num5 / 2000, '*') << "\n";
    cout << setw(7) << "6" << setw(15) << num6 << string(num6 / 2000, '*') << "\n";
    cout << setw(7) << "7" << setw(15) << num7 << string(num7 / 2000, '*') << "\n";
    cout << setw(7) << "8" << setw(15) << num8 << string(num8 / 2000, '*') << "\n";
    cout << setw(7) << "9" << setw(15) << num9 << string(num9 / 2000, '*') << "\n";
}
