all: BookMain

BookMain: Book_main.o Record.o
	g++ -std=c++11 Book_main.o Record.o -o BookMain

Book_main.o:
	g++ -std=c++11 -c Book_main.cpp
	
Record.o:
	g++ -std=c++11 -c Record.cpp

clean:
	rm *.o BookMain
