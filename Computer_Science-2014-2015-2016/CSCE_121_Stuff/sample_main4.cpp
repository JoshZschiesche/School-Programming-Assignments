#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
try {
  if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);
  Simple_window win1(Point(100,200),600,400,"two lines");
  Line diagonal(Point(100,100),Point(400,500));  // make a diagonal line
  Line vertical(Point(150,50),Point(150,150));   // make a vertical line
  win1.attach(diagonal);
  win1.attach(vertical);
  vertical.set_color(Color::magenta);
  win1.wait_for_button();
  return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}