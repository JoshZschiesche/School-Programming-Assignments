#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>
#include <list>
#include <string>
#include <vector>
#include <iostream>

#include "Edge.hpp"
using namespace std;

class Vertex 
{
public:
    // the label of this vertex
    int label;
    // using a linked-list to manage its edges which offers O(c) insertion
    list<Edge*> edgeList;
    
    // init your vertex here
    Vertex(int lbl);
	
    // connect this vertex to a specific vertex (adding edge)
    void connectTo(int end);
};
ostream& operator<<(ostream& out, const Vertex vx);
#endif /* Vertex_hpp */