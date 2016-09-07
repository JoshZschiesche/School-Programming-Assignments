OBJ = main.o Graph.o Vertex.o Edge.o
MAIN = main

$(MAIN): $(OBJ)
	g++ -std=c++11 -Wall -Wno-sign-compare -g -o $(MAIN) $(OBJ)

main.o: main.cpp
	g++ -std=c++11 -Wall -Wno-sign-compare -g -c main.cpp

Graph.o: Graph.cpp Graph.hpp
	g++ -std=c++11 -Wall -Wno-sign-compare -g -c Graph.cpp

Vertex.o: Vertex.cpp Vertex.hpp
	g++ -std=c++11 -Wall -Wno-sign-compare -g -c Vertex.cpp

Edge.o: Edge.cpp Edge.hpp
	g++ -std=c++11 -Wall -Wno-sign-compare -g -c Edge.cpp

clean: 
	rm -f $(OBJ) $(MAIN)
