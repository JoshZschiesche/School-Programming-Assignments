//Josh Zschiesche
//CSCE 121-502
//Due: October 27,2015
//hw6pr4.cpp

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

String country_name = "";

class Scandenavian_Flag : Shape
{
	Color fg;
	Color bg;
	Color rg;
	
	public:
	Vector_ref<Rectangle> foo;
	
	Scandenavian_Flag (Color back, Color front, Color midd):
	
	bg(back), fg(front), rg(midd)
	{
		foo.push_back(new Rectangle{Point{100,100}, Point{600,200}});
		foo.push_back(new Rectangle{Point{100,200}, Point{600,300}});
		foo.push_back(new Rectangle{Point{100,300}, Point{600,400}});
	
		foo[0].set_fill_color(back);
		foo[1].set_fill_color(midd);
		foo[2].set_fill_color(front);
		
		foo[0].set_color(Color::invisible);
		foo[1].set_color(Color::invisible);
		foo[2].set_color(Color::invisible);
		
	}
};

int main()
{
	
	Simple_window win1(Point(100,200),800,600,"Problem 4 of Homework 6");
	win1.show();
	while (true)
	{
	
	country_name = "Russia";
	Scandenavian_Flag Denmark(Color::red, Color::white, Color::blue);
	
	win1.attach(Denmark.foo[0]);
	Fl::flush();
	Fl::redraw();
	win1.attach(Denmark.foo[1]);
	Fl::flush();
	Fl::redraw();
	win1.attach(Denmark.foo[2]);
	Fl::flush();
	Fl::redraw();
	
	Text t1{Point{100,480}, country_name};
	win1.attach(t1);
	Fl::flush();
	Fl::redraw();
	
	system("sleep 5");
	
	win1.detach(Denmark.foo[0]);
	win1.detach(Denmark.foo[1]);
	win1.detach(Denmark.foo[2]);
	
	win1.detach(t1);
	
	country_name = "Estonia";
	Scandenavian_Flag Sweden(Color::white, Color::blue, Color::black);
	
	win1.attach(Sweden.foo[0]);
	win1.attach(Sweden.foo[1]);
	win1.attach(Sweden.foo[2]);
	
	Text t2{Point{100,480}, country_name};
	win1.attach(t2);
	
	
	system("sleep 5");
	
	win1.detach(Sweden.foo[0]);
	win1.detach(Sweden.foo[1]);
	win1.detach(Sweden.foo[2]);
	
	win1.detach(t2);
	
	country_name = "Yemen";
	Scandenavian_Flag Finland(Color::red, Color::white, Color::black);
	return Fl::run();
	
	win1.attach(Finland.foo[0]);
	win1.attach(Finland.foo[1]);
	win1.attach(Finland.foo[2]);
	
	Text t3{Point{100,480}, country_name};
	win1.attach(t3);
	
	Fl::flush();
	Fl::redraw();
	}
}