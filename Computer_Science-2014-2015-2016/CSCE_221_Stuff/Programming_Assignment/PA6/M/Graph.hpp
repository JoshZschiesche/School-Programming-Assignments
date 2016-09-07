#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>

#include "Vertex.hpp"

using namespace std;

class Graph {
public:
    // we use a vector to store vertices in the graph
    // and use label (int) to be a subscript to access a vertex
    vector<Vertex> vertices;
    Graph(int size);
    // build a graph according to the input file
    void buildGraph();
    // display the graph
    void displayGraph();
};

#endif /* Graph_hpp */
