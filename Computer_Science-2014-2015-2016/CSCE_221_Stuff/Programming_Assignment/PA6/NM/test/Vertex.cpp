// please implement it

#include "Vertex.hpp"


void Vertex::connectTo(int end)
{
	Edge *edge = new Edge(label, end, label+end);
	edgeList.push_back(edge);
}

Vertex::Vertex(int lbl)
{
	label = lbl;
}

Vertex::Vertex()
{
	label = 0;
}

ostream& operator<<(ostream& out, const Vertex vx)
{
	out << vx.label << ": ";
	list<Edge*> temp = vx.edgeList;
	while(temp.size() > 0)
	{
		out << temp.front()->end << " ";
		temp.pop_front();
	}
	out << endl;
}