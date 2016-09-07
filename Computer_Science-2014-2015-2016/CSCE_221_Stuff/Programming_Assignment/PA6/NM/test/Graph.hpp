#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>

#include "Vertex.hpp"

using namespace std;

class Graph 
{
public:
    // we use a vector to store vertices in the graph
    // and use label (int) to be a subscript to access a vertex
    vector<Vertex> vertices;
    Graph(int size);
    // build a graph according to the input file
    void buildGraph(const char * argv);
    // display the graph
    void displayGraph();
	
//////Custom Functions//////////////////////////////////////////////////////////////////////////////////////

	//I needed the size
	int return_size();
	//Debth First Search Implementation
	void DFS(int start);
};

#endif /* Graph_hpp */
