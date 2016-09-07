#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Simple_window win1(Point(100,200),1000,1000,"two lines");
	
	Line lineJ1{Point{50,50}, Point{50,70}};
	win1.attach(lineJ1);
	
	Line lineJ2(Point(50,50), Point(500,50));
	win1.attach(lineJ2);
	
	Line lineJ3(Point(50,50), Point(50,70));
	win1.attach(lineJ3);
	
	Line lineJ4(Point(50,50), Point(50,70));
	win1.attach(lineJ4);
	
	//Line lineZ1(Point(50,30), Point(525,750));
	//win1.attach(lineZ1);
	
	win1.wait_for_button();
}