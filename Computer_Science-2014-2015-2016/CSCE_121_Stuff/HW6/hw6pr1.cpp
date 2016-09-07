//Josh Zschiesche
//CSCE 121-502
//Due October 27, 2015
//hw6pr1.cpp

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
int main()
{
try {
  if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);
  Simple_window win1(Point(100,200),600,600,"chess board");
  
  //row 1
  
  Rectangle rec11 {Point{10,10},Point{50,50}};
  Rectangle rec12 {Point{50,10},Point{90,50}};
  Rectangle rec13 {Point{90,10},Point{130,50}};
  Rectangle rec14 {Point{130,10},Point{170,50}};
  Rectangle rec15 {Point{170,10},Point{210,50}};
  Rectangle rec16 {Point{210,10},Point{250,50}};
  Rectangle rec17 {Point{250,10},Point{290,50}};
  Rectangle rec18 {Point{290,10},Point{330,50}};
  
  //row 2
  
  Rectangle rec21 {Point{10,50},Point{50,90}};
  Rectangle rec22 {Point{50,50},Point{90,90}};
  Rectangle rec23 {Point{90,50},Point{130,90}};
  Rectangle rec24 {Point{130,50},Point{170,90}};
  Rectangle rec25 {Point{170,50},Point{210,90}};
  Rectangle rec26 {Point{210,50},Point{250,90}};
  Rectangle rec27 {Point{250,50},Point{290,90}};
  Rectangle rec28 {Point{290,50},Point{330,90}};
  
  //row 3
  
  Rectangle rec31 {Point{10,90},Point{50,130}};
  Rectangle rec32 {Point{50,90},Point{90,130}};
  Rectangle rec33 {Point{90,90},Point{130,130}};
  Rectangle rec34 {Point{130,90},Point{170,130}};
  Rectangle rec35 {Point{170,90},Point{210,130}};
  Rectangle rec36 {Point{210,90},Point{250,130}};
  Rectangle rec37 {Point{250,90},Point{290,130}};
  Rectangle rec38 {Point{290,90},Point{330,130}};
  
  //row 4
  
  Rectangle rec41 {Point{10,130},Point{50,170}};
  Rectangle rec42 {Point{50,130},Point{90,170}};
  Rectangle rec43 {Point{90,130},Point{130,170}};
  Rectangle rec44 {Point{130,130},Point{170,170}};
  Rectangle rec45 {Point{170,130},Point{210,170}};
  Rectangle rec46 {Point{210,130},Point{250,170}};
  Rectangle rec47 {Point{250,130},Point{290,170}};
  Rectangle rec48 {Point{290,130},Point{330,170}};
  
  //row 5
  
  Rectangle rec51 {Point{10,170},Point{50,210}};
  Rectangle rec52 {Point{50,170},Point{90,210}};
  Rectangle rec53 {Point{90,170},Point{130,210}};
  Rectangle rec54 {Point{130,170},Point{170,210}};
  Rectangle rec55 {Point{170,170},Point{210,210}};
  Rectangle rec56 {Point{210,170},Point{250,210}};
  Rectangle rec57 {Point{250,170},Point{290,210}};
  Rectangle rec58 {Point{290,170},Point{330,210}};
  
  //row 6
  
  Rectangle rec61 {Point{10,210},Point{50,250}};
  Rectangle rec62 {Point{50,210},Point{90,250}};
  Rectangle rec63 {Point{90,210},Point{130,250}};
  Rectangle rec64 {Point{130,210},Point{170,250}};
  Rectangle rec65 {Point{170,210},Point{210,250}};
  Rectangle rec66 {Point{210,210},Point{250,250}};
  Rectangle rec67 {Point{250,210},Point{290,250}};
  Rectangle rec68 {Point{290,210},Point{330,250}};
  
  //row 7
  
  Rectangle rec71 {Point{10,250},Point{50,290}};
  Rectangle rec72 {Point{50,250},Point{90,290}};
  Rectangle rec73 {Point{90,250},Point{130,290}};
  Rectangle rec74 {Point{130,250},Point{170,290}};
  Rectangle rec75 {Point{170,250},Point{210,290}};
  Rectangle rec76 {Point{210,250},Point{250,290}};
  Rectangle rec77 {Point{250,250},Point{290,290}};
  Rectangle rec78 {Point{290,250},Point{330,290}};
  
  //row 8
  
  Rectangle rec81 {Point{10,290},Point{50,330}};
  Rectangle rec82 {Point{50,290},Point{90,330}};
  Rectangle rec83 {Point{90,290},Point{130,330}};
  Rectangle rec84 {Point{130,290},Point{170,330}};
  Rectangle rec85 {Point{170,290},Point{210,330}};
  Rectangle rec86 {Point{210,290},Point{250,330}};
  Rectangle rec87 {Point{250,290},Point{290,330}};
  Rectangle rec88 {Point{290,290},Point{330,330}};
  
  //row 1
  
  rec11.set_fill_color(Color::yellow);
  rec12.set_fill_color(Color::blue);
  rec13.set_fill_color(Color::yellow);
  rec14.set_fill_color(Color::blue);
  rec15.set_fill_color(Color::yellow);
  rec16.set_fill_color(Color::blue);
  rec17.set_fill_color(Color::yellow);
  rec18.set_fill_color(Color::blue);
  
  //row 2
  
  rec21.set_fill_color(Color::blue);
  rec22.set_fill_color(Color::yellow);
  rec23.set_fill_color(Color::blue);
  rec24.set_fill_color(Color::yellow);
  rec25.set_fill_color(Color::blue);
  rec26.set_fill_color(Color::yellow);
  rec27.set_fill_color(Color::blue);
  rec28.set_fill_color(Color::yellow);
  
  //row 3
  
  rec31.set_fill_color(Color::yellow);
  rec32.set_fill_color(Color::blue);
  rec33.set_fill_color(Color::yellow);
  rec34.set_fill_color(Color::blue);
  rec35.set_fill_color(Color::yellow);
  rec36.set_fill_color(Color::blue);
  rec37.set_fill_color(Color::yellow);
  rec38.set_fill_color(Color::blue);
  
  //row 4
  
  rec41.set_fill_color(Color::blue);
  rec42.set_fill_color(Color::yellow);
  rec43.set_fill_color(Color::blue);
  rec44.set_fill_color(Color::yellow);
  rec45.set_fill_color(Color::blue);
  rec46.set_fill_color(Color::yellow);
  rec47.set_fill_color(Color::blue);
  rec48.set_fill_color(Color::yellow);
  
  //row 5
  
  rec51.set_fill_color(Color::yellow);
  rec52.set_fill_color(Color::blue);
  rec53.set_fill_color(Color::yellow);
  rec54.set_fill_color(Color::blue);
  rec55.set_fill_color(Color::yellow);
  rec56.set_fill_color(Color::blue);
  rec57.set_fill_color(Color::yellow);
  rec58.set_fill_color(Color::blue);
  
  //row 6
  
  rec61.set_fill_color(Color::blue);
  rec62.set_fill_color(Color::yellow);
  rec63.set_fill_color(Color::blue);
  rec64.set_fill_color(Color::yellow);
  rec65.set_fill_color(Color::blue);
  rec66.set_fill_color(Color::yellow);
  rec67.set_fill_color(Color::blue);
  rec68.set_fill_color(Color::yellow);
  
  //row 7
  
  rec71.set_fill_color(Color::yellow);
  rec72.set_fill_color(Color::blue);
  rec73.set_fill_color(Color::yellow);
  rec74.set_fill_color(Color::blue);
  rec75.set_fill_color(Color::yellow);
  rec76.set_fill_color(Color::blue);
  rec77.set_fill_color(Color::yellow);
  rec78.set_fill_color(Color::blue);
  
  //row 8
  
  rec81.set_fill_color(Color::blue);
  rec82.set_fill_color(Color::yellow);
  rec83.set_fill_color(Color::blue);
  rec84.set_fill_color(Color::yellow);
  rec85.set_fill_color(Color::blue);
  rec86.set_fill_color(Color::yellow);
  rec87.set_fill_color(Color::blue);
  rec88.set_fill_color(Color::yellow);
 
  //row 1
 
  win1.attach(rec11);
  win1.attach(rec12);
  win1.attach(rec13);
  win1.attach(rec14);
  win1.attach(rec15);
  win1.attach(rec16);
  win1.attach(rec17);
  win1.attach(rec18);
  
  //row 2
  
  win1.attach(rec21);
  win1.attach(rec22);
  win1.attach(rec23);
  win1.attach(rec24);
  win1.attach(rec25);
  win1.attach(rec26);
  win1.attach(rec27);
  win1.attach(rec28);
  
  //row 3
  
  win1.attach(rec31);
  win1.attach(rec32);
  win1.attach(rec33);
  win1.attach(rec34);
  win1.attach(rec35);
  win1.attach(rec36);
  win1.attach(rec37);
  win1.attach(rec38);
  
  //row 4
  
  win1.attach(rec41);
  win1.attach(rec42);
  win1.attach(rec43);
  win1.attach(rec44);
  win1.attach(rec45);
  win1.attach(rec46);
  win1.attach(rec47);
  win1.attach(rec48);
  
  //row 5
  
  win1.attach(rec51);
  win1.attach(rec52);
  win1.attach(rec53);
  win1.attach(rec54);
  win1.attach(rec55);
  win1.attach(rec56);
  win1.attach(rec57);
  win1.attach(rec58);
  
  //row 6
  
  win1.attach(rec61);
  win1.attach(rec62);
  win1.attach(rec63);
  win1.attach(rec64);
  win1.attach(rec65);
  win1.attach(rec66);
  win1.attach(rec67);
  win1.attach(rec68);
  
  //row 7
  
  win1.attach(rec71);
  win1.attach(rec72);
  win1.attach(rec73);
  win1.attach(rec74);
  win1.attach(rec75);
  win1.attach(rec76);
  win1.attach(rec77);
  win1.attach(rec78);
  
  //row8
  
  win1.attach(rec81);
  win1.attach(rec82);
  win1.attach(rec83);
  win1.attach(rec84);
  win1.attach(rec85);
  win1.attach(rec86);
  win1.attach(rec87);
  win1.attach(rec88);
  
  //make stuff invisible
  
  rec11.set_color(Color::invisible);
  rec12.set_color(Color::invisible);
  rec13.set_color(Color::invisible);
  rec14.set_color(Color::invisible);
  rec15.set_color(Color::invisible);
  rec16.set_color(Color::invisible);
  rec17.set_color(Color::invisible);
  rec18.set_color(Color::invisible);
  rec21.set_color(Color::invisible);
  rec22.set_color(Color::invisible);
  rec23.set_color(Color::invisible);
  rec24.set_color(Color::invisible);
  rec25.set_color(Color::invisible);
  rec26.set_color(Color::invisible);
  rec27.set_color(Color::invisible);
  rec28.set_color(Color::invisible);
  rec31.set_color(Color::invisible);
  rec32.set_color(Color::invisible);
  rec33.set_color(Color::invisible);
  rec34.set_color(Color::invisible);
  rec35.set_color(Color::invisible);
  rec36.set_color(Color::invisible);
  rec37.set_color(Color::invisible);
  rec38.set_color(Color::invisible);
  rec41.set_color(Color::invisible);
  rec42.set_color(Color::invisible);
  rec43.set_color(Color::invisible);
  rec44.set_color(Color::invisible);
  rec45.set_color(Color::invisible);
  rec46.set_color(Color::invisible);
  rec47.set_color(Color::invisible);
  rec48.set_color(Color::invisible);
  rec51.set_color(Color::invisible);
  rec52.set_color(Color::invisible);
  rec53.set_color(Color::invisible);
  rec54.set_color(Color::invisible);
  rec55.set_color(Color::invisible);
  rec56.set_color(Color::invisible);
  rec57.set_color(Color::invisible);
  rec58.set_color(Color::invisible);
  rec61.set_color(Color::invisible);
  rec62.set_color(Color::invisible);
  rec63.set_color(Color::invisible);
  rec64.set_color(Color::invisible);
  rec65.set_color(Color::invisible);
  rec66.set_color(Color::invisible);
  rec67.set_color(Color::invisible);
  rec68.set_color(Color::invisible);
  rec71.set_color(Color::invisible);
  rec72.set_color(Color::invisible);
  rec73.set_color(Color::invisible);
  rec74.set_color(Color::invisible);
  rec75.set_color(Color::invisible);
  rec76.set_color(Color::invisible);
  rec77.set_color(Color::invisible);
  rec78.set_color(Color::invisible);
  rec81.set_color(Color::invisible);
  rec82.set_color(Color::invisible);
  rec83.set_color(Color::invisible);
  rec84.set_color(Color::invisible);
  rec85.set_color(Color::invisible);
  rec86.set_color(Color::invisible);
  rec87.set_color(Color::invisible);
  rec88.set_color(Color::invisible);
  
  win1.wait_for_button();
  return 0;
}
catch(exception& e) 
{
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) 
{
	cerr << "Some exception\n";
	return 2;
}
}