// please implement it

//http://www.programming-techniques.com/2012/07/depth-first-search-in-c-algorithm-and.html
//http://stackoverflow.com/questions/27676416/time-complexity-for-transposing-a-graph
//http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/

#include "Graph.hpp"
#include <stack>
#include <sstream>
#include <map>
#include <algorithm>

Graph::Graph(int size)
{
}

int Graph::return_size()
{
	return vertices.size();
}

void Graph::buildGraph(const char * bar)
{
	ifstream stream0;
	stream0.open(bar);
	
	while(!stream0.eof())
	{
		int foo;
		string s;
		
		getline(stream0,s);
		stringstream stream1(s.c_str());
		
		stream1 >> foo;
		Vertex newVert(foo);
		stream1 >> foo;
		while( foo != -1)
		{
			newVert.connectTo(foo);
			stream1 >> foo;
		}
		vertices.push_back(newVert);
	}
}

void Graph::displayGraph()
{
	for(int i = 0; i < vertices.size(); i++)
	{
		cout << vertices[i];
	}
}

void Graph::displayStronglyConnected(vector<int>& foo)
{
	for(int i = 0; i < vertices.size(); i++)
	{
		if(find(foo.begin(), foo.end(), vertices[i].label) != foo.end())
		{
			cout << vertices[i].label << ": ";
			
			for (Edge* edge : vertices[i].edgeList)
			{
				if (find(foo.begin(), foo.end(), edge->end) != foo.end())
				{
					cout << edge->end << " ";
				}
			}
			cout << "-1" << endl;
		}
	}
}


//everything below is new
//This is the Depth First Search
vector<vector<int>> Graph::DFS(int Start)
{
	vector<vector<int>> messy;
	
	map<int,bool> my_map;
	
	for(int i = 1; i < vertices.size()+1; ++i)
	{
		my_map[i] = false;
	}
	
	for(int i = 1; i < vertices.size()+1; ++i)
	{
		if (my_map[i] == false)
		{
			vector<int> m;
			DFS_Util(i, my_map, m);
			cout << endl;
			messy.push_back(m);
		}
	}
	
	return messy;
}

//This is the Utility function of the Debth First Search
void Graph::DFS_Util(int i, map<int,bool>& my_map, vector<int>& ack)
{
	int next = 0;
	
	if(my_map[i] == false)
	{
		my_map[i] = true;
		cout << vertices[i-1].label;
		ack.push_back(vertices[i-1].label);
		
		for (auto edge:vertices[i-1].edgeList)
		{
			if(my_map[edge->end] == false)
			{
				next = edge->end;
				DFS_Util(next, my_map, ack);
			}
		}
	}
}
//http://www.geeksforgeeks.org/connectivity-in-a-directed-graph/

//This is the Traspose of the graph fuction
void Graph::getTranspose(Graph& grph)
{
	for (int c = 0; c < vertices.size(); ++c)
	{
		grph.vertices.push_back(Vertex(c+1));
	}
	for (int j = 0; j < vertices.size(); ++j)
    {
        // Recur for all the vertices adjacent to this vertex
        for(auto i = vertices[j].edgeList.begin(); i != vertices[j].edgeList.end(); ++i)
        {
            grph.vertices[(*i)->end-1].connectTo((*i)->start);
        }
    }
}