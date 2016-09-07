#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

String country;
class Scandenavian_Flag : Shape
{
	Color fg;
	Color bg;
	Color rg;
	
	public:
	Vector_ref<Rectangle> foo;
	String country_name;
	
	Scandenavian_Flag (Color back, Color front, Color midd, String country):
	bg(back), fg(front), rg(midd), country_name(country)
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
	vector<Scandenavian_Flag> flags;
	Simple_window win1(Point(100,200),800,600,"Problem 3 of Homework 3");
	
	Scandenavian_Flag f1(Color::white, Color::blue,Color::black, "Estonia");
	flags.push_back(f1);
	//flags.push_back(Scandenavian_Flag(Color::black,Color::red,Color::yellow, "Germany"));
	
	for(int i = 0; i < flags.size(); i++)
	{
		for(int j = 0; j < flags[i].foo.size();  j++)
		{
			win1.attach(flags[i].foo[j]);
		}
		system("sleep 5");
		for(int j = 0; j < flags[i].foo.size();  j++)
		{
			win1.detach(flags[i].foo[j]);
		}
	}
}