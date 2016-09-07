#include <iostream>
#include <fstream>

#include "Graph.hpp"
using namespace std;

int main(int intiger, const char * arr1[]) 
{
    // insert code here...
	ifstream main_stream;
	main_stream.open(arr1[intiger-1]);
	int size = 0;
	
	while(!main_stream.eof())
	{
		string ss;
		getline(main_stream,ss);
		size++;
	}
	
	Graph grp(size+1);
	grp.buildGraph(arr1[intiger-1]);
	grp.displayGraph();
	
	////////////////////////Part 1 Above
	
	////////////////////////Part 2 Below
	
	cout << "Part 1 complete" << endl << endl;
	cout << "Size is: " << grp.return_size() << endl << endl;
	cout << "Debth first search is: " << endl;
	
	grp.DFS(grp.vertices[1].label);
	
	Graph gt(size+1);
	grp.getTranspose(gt);
	
	cout << "The Transpose graph is:" << endl;
	gt.displayGraph();
	
	cout << "The connected components of the Transpose Graph: " << endl;
	auto m = gt.DFS(gt.vertices[1].label);
	
	vector<int> store;
	for (vector<int>& vec : m)
	{
		store.push_back(vec[0]);
	}
	cout << endl;
	cout << "This is the acyclic components:" << endl;
	grp.displayStronglyConnected(store);
	
    return 0;
}