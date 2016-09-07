#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"
#include "std_lib_facilities_4.h"
#include "Point.h"
#include "find_solution.h"
#include "playerInfo.h"
#include <unistd.h>
#include <FL/Fl_Box.H>
#include "sWindow.h"

int main()
{
	sWindow win(Point{100,100}, 825,675, "Flip Flaps");
    return gui_main();
}