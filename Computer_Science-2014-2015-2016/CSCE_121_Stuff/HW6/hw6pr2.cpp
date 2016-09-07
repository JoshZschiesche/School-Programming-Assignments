//Josh Zschiesche
//CSCE 121-502
//Due: October 27,2015
//hw6pr2.cpp

#include "randint.h"
#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);
  Simple_window win1(Point(100,200),800,600,"Histogram of hw6pr2.cpp");
  
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

    for (int i = 0; i <= 5000; ++i)
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
	
	Text t{Point{30,40},"Histogram of Number Frequency"};
	Text s{Point{30,480}, "One Tick Mark = 10 Occurances"};
	Text zero{Point{10,70}, "0"};
	Text one{Point{10,110}, "1"};
	Text two{Point{10,150}, "2"};
	Text three{Point{10,190}, "3"};
	Text four{Point{10,230}, "4"};
	Text five{Point{10,270}, "5"};
	Text six{Point{10,310}, "6"};
	Text seven{Point{10,350}, "7"};
	Text eight{Point{10,390}, "8"};
	Text nine{Point{10,430}, "9"};
	
	///////////////////////////////////////////////////////////////
	
    Rectangle rec_for_0 {Point{30,50},num0,30};
	Rectangle rec_for_1 {Point{30,90},num1,30};
	Rectangle rec_for_2 {Point{30,130},num2,30};
	Rectangle rec_for_3 {Point{30,170},num3,30};
	Rectangle rec_for_4 {Point{30,210},num4,30};
	Rectangle rec_for_5 {Point{30,250},num5,30};
	Rectangle rec_for_6 {Point{30,290},num6,30};
	Rectangle rec_for_7 {Point{30,330},num7,30};
	Rectangle rec_for_8 {Point{30,370},num8,30};
	Rectangle rec_for_9 {Point{30,410},num1,30};
	
	rec_for_0.set_fill_color(Color::yellow);
	rec_for_1.set_fill_color(Color::green);
	rec_for_2.set_fill_color(Color::blue);
	rec_for_3.set_fill_color(Color::white);
	rec_for_4.set_fill_color(Color::red);
	rec_for_5.set_fill_color(Color::black);
	rec_for_6.set_fill_color(Color::cyan);
	rec_for_7.set_fill_color(Color::magenta);
	rec_for_8.set_fill_color(Color::dark_red);
	rec_for_9.set_fill_color(Color::dark_green);
	
	win1.attach(rec_for_0);
	win1.attach(rec_for_1);
	win1.attach(rec_for_2);
	win1.attach(rec_for_3);
	win1.attach(rec_for_4);
	win1.attach(rec_for_5);
	win1.attach(rec_for_6);
	win1.attach(rec_for_7);
	win1.attach(rec_for_8);
	win1.attach(rec_for_9);
	
	win1.attach(t);
	
	win1.attach(zero);
	win1.attach(one);
	win1.attach(two);
	win1.attach(three);
	win1.attach(four);
	win1.attach(five);
	win1.attach(six);
	win1.attach(seven);
	win1.attach(eight);
	win1.attach(nine);
	
	Axis xa {Axis::x, Point{30,450}, 600, 60, "Number of Occurances"};
	win1.attach(xa);
	win1.attach(s);
	win1.wait_for_button();
	return 0;
}
