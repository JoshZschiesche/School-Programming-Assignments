//Josh Zschiesche
//CSCE 121-502
//Due: October 27,2015
//hw6pr3.cpp

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

String country_name = "";

class Scandenavian_Flag : Shape
{
	Color fg;
	Color bg;
	
	public:
	
	Scandenavian_Flag (Color back, Color front):
	
	bg(back), fg(front)
	{
		Simple_window win1(Point(100,200),800,600,"Problem 3 of Homework 3");
	
		Rectangle back_rect{Point{100,100},Point{600,400}};
		Rectangle vertical_rect{Point{190,100}, Point{230,400}};
		Rectangle horozontal_rect{Point{100,230}, Point{600,270}};
	
		back_rect.set_fill_color(back);
		vertical_rect.set_fill_color(front);
		horozontal_rect.set_fill_color(front);
		
		back_rect.set_color(Color::invisible);
		vertical_rect.set_color(Color::invisible);
		horozontal_rect.set_color(Color::invisible);
		
		win1.attach(back_rect);
		win1.attach(vertical_rect);
		win1.attach(horozontal_rect);
		
		Text t{Point{100,480}, country_name};
		Text s{Point{100,550}, "Press 'Next' For the Next Flag"};
		
		win1.attach(t);
		win1.attach(s);
		win1.wait_for_button();
	}
};

int main()
{
	country_name = "Denmark";
	Scandenavian_Flag Denmark(Color::red, Color::white);
	
	country_name = "Sweden";
	Scandenavian_Flag Sweden(Color::blue, Color::yellow);
	
	country_name = "Finland";
	Scandenavian_Flag Finland(Color::white, Color::blue);
	
}