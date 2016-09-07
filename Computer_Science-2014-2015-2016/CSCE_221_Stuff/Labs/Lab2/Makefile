all: Main.o Enclosure.o Vendor.o Animal.o Worker.o Cage.o
	g++-4.7 -std=c++11 Main.o Enclosure.o Vendor.o Animal.o Worker.o Cage.o -o main
Cage.o: Cage.cpp Cage.h
	g++-4.7 -std=c++11 -g -c Cage.cpp
Worker.o: Worker.cpp Worker.h Food.h
	g++-4.7 -std=c++11 -g -c Worker.cpp
Animal.o: Animal.cpp Animal.h Food.h
	g++-4.7 -std=c++11 -g -c Animal.cpp
Vendor.o: Vendor.cpp Vendor.h Worker.h Food.h
	g++-4.7 -std=c++11 -g -c Vendor.cpp
Enclosure.o: Enclosure.cpp Enclosure.h Animal.h Worker.h Plant.h Cage.h Food.h
	g++-4.7 -std=c++11 -g -c Enclosure.cpp
Main.o: Main.cpp Vendor.h Enclosure.h Animal.h Worker.h Plant.h Cage.h Food.h
	g++-4.7 -std=c++11 -g -c Main.cpp
clean:
	rm *.o main
	
