// please implement it
// http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/GraphAlgor/graphIntro.htm
#include "Graph.hpp"
#include <stack>
#include <sstream>
#include <map>

Graph::Graph(int size)
{
	vertices.resize(size);
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
		
		while( foo != -1)
		{
			stream1 >> foo;
			newVert.connectTo(foo);
		}
		vertices[newVert.label] = newVert;
	}
}

void Graph::displayGraph()
{
	for(int i = 1; i < vertices.size(); i++)
	{
		cout << vertices[i];
	}
}


//everything below is new
void Graph::DFS(int Start)
{
	map<int,bool> my_map;
	
	for(int i = 1; i < vertices.size()+1; ++i)
	{
		my_map[i] = false;
	}
	
	int next = 0;
	
	cout << "Before for Loop" << '\n';
	
	for(int i = 0; vertices.size();)
	{
		if(my_map[i+1] == false)
		{
			cout << vertices[i];
			my_map[i+1] = true;
			
			for (auto edge:vertices[i].edgeList)
			{
				if(my_map[edge->end] == false)
				{
					next = edge->end;
					break;
				}
			}
		}
		
		else
		{
			++i;
		}
	}
	
	/* bool* visited = new bool[this->vertices.size()]();
    stack<int> stack;
    stack.push(Start);
    vector<int>::iterator i;
    cout << "DFS: ";
    while(!stack.empty())
    {
        int top = stack.top();
        cout << top << " ";
        stack.pop();
        visited[top] = true;
        for(i = vertices[top].begin(); i != vertices[top].end(); i++)
        {
            if (!visited[*i])
                stack.push(*i);
        }
    }
    cout << endl; */
}

//http://www.programming-techniques.com/2012/07/depth-first-search-in-c-algorithm-and.html
//http://stackoverflow.com/questions/27676416/time-complexity-for-transposing-a-graph
//http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
/*void Graph::debthFirstSearch(Vertex vert, int& d) //comment this if can't get working*/