#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>

#include "Vertex.hpp"

#include <map>

using namespace std;

class Graph 
{
public:
    // we use a vector to store vertices in the graph
    // and use label (int) to be a subscript to access a vertex
    vector<Vertex> vertices;
    Graph(int size);
    // build a graph according to the input file
    void buildGraph(const char * bar);
    // display the graph
    void displayGraph();
	
//////Custom Functions//////////////////////////////////////////////////////////////////////////////////////

	//I needed the size
	int return_size();
	//Debth First Search Implementation
	vector<vector<int>> DFS(int start);
	
	void DFS_Util(int i, map<int,bool>& my_map, vector<int>&);
	
	void getTranspose(Graph& grph);
	
	void displayStronglyConnected(vector<int>& foo);
	
};

#endif /* Graph_hpp */
