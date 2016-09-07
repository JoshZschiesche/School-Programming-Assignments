// please implement it

#include "Vertex.hpp"
Vertex::Vertex(int lbl)
{
	label = lbl;
}

void Vertex::connectTo(int end)
{
	Edge *edge = new Edge(label, end, 0);
	edgeList.push_back(edge);
}

ostream& operator<<(ostream& out, const Vertex vert)
{
	out << vert.label << ": ";
	list<Edge*> t = vert.edgeList;
	
	while(t.size() > 0)
	{
		out << t.front()->end << " ";
		t.pop_front();
	}
	cout << "-1";
	cout << endl;
	return out;
}