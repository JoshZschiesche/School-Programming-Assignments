OBJ = main.o Graph.o Vertex.o Edge.o
MAIN = main

$(MAIN): $(OBJ)
	g++ -std=c++11 -Wall -g -o $(MAIN) $(OBJ)

main.o: main.cpp
	g++ -std=c++11 -Wall -g -c main.cpp

Graph.o: Graph.cpp Graph.hpp
	g++ -std=c++11 -Wall -g -c Graph.cpp

Vertex.o: Vertex.cpp Vertex.hpp
	g++ -std=c++11 -Wall -g -c Vertex.cpp

Edge.o: Edge.cpp Edge.hpp
	g++ -std=c++11 -Wall -g -c Edge.cpp

clean: 
	rm -f $(OBJ) $(MAIN)
