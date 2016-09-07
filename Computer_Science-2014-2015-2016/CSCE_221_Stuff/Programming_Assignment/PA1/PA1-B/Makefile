all: My_vec.o main.o
	g++ -std=c++11 My_vec.o main.o -o main -g
My_vec.o: My_vec.cpp My_vec.h
	g++ -std=c++11 -c My_vec.cpp -g
main.o: main.cpp My_vec.h
	g++ -std=c++11 -c main.cpp -g
clean:
	rm *.o main
