Welcome to Flip Flaps!
Read fully please!!
How to Play:
Clicking the Pos: X (Where X is replaced with a number) will flip the top of the stack (starting from the position you clicked)
Compile the game using whatever software you usually use (must be compatible with FLTK). We compiled on build.tamu.edu using the command g++ -std=c++14 -g *.cpp find_solution.o -lfltk -lfltk_images && ./a.out with all of the files in the same folder.
When you first run the game the splash screen should appear, offering basic instructions on how to play the game and information on the game developers.
The start screen allows you to pick a level of difficulty, which decides how many pancakes you will need to sort in increasing order.
The game will compile if there is a Word doc inside it, however it is preferred if that is not in the folder used to compile all of the other files.
After you select your desired level, the game will create a random stack of pancakes and give you buttons to click on the right, which flips the stack from that point up
Each level gives you a time limit that increases with difficulty, so you’ll have to flip fast.
If you need any hints, you can click the hint button, which will tell you which Pos: X to click next
Be conservative with your flips, however, because every flip you do takes away points from your score, and if that reaches zero or the time runs out, it’s game over! (Score will not be saved)
If you win the game or run out of time, you’ll be asked to enter your initials to see if you made it onto the High Scores!
Once you win or lose you’ll be able to continue playing.
Quit the game at any time by pressing the “Quit” button
Your score will start out as -1 until you click a pos: button and will save that score (even if the time runs out) unless score = 0.
When you go to enter the initials, it will take almost all input except for strings longer than 3 characters, and it will not accept strings that contain spaces. These will spell “INVALID INPUT” on the window.
Anything that outputs to the console was just for our debug purposes that we didn’t have time to comment out and is not meant to be part of the game.
Note: DO NOT  SPAM BUTTONS ON THE 8th/9th LEVEL, IT TAKES A SECOND TO SWAP/FIND THE SOLUTION & HINT CLICK SLOW AND IT WILL WORK.


Your header should look like the following:

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

You should also have the following .jpg files in the same directory when compiling:

gameover.jpg
Pancakes.jpg
Winner.jpg

These Files should be in the Directory (To comile the way we compiled):

find_solution.h
find_solution.o
Graph.cpp/Graph.h/Graph.o
GUI.cpp/GUI.h/GUI.o
playerinfo.h
Point.h
Project_Team34.cpp
Scores.txt
Simple_window.cpp/Simple_window.h/Simple_window.o
std_lib_facilities_4.h
sWindow.h
Window.cpp
Window.h
Window.o

You have the option of having a Scores.txt file in the folder (the file can be filled or empty) The game will make a Scores.txt file if one does not exist

If there are any problems please contact Josh Zschiesche, Aldair Rosado, Madison Smith, or Marc Sustaita

Contact:
jzschiesche1@tamu.edu (Josh Zschiesche)
madison.smith73@tamu.edu (Madison Smith)
marc_sustaita@tamu.edu (Marc Sustatia)
aldairrosado@tamu.edu (Aldair Rosado)