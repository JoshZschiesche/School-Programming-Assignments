all: main.o
	g++ -std=c++11 main.o -o main -g
main.o: main.cpp My_vec_temp.h
	g++ -std=c++11 -c main.cpp -g
clean:
	rm *.o main
