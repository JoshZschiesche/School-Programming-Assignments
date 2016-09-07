// please implement it

#include "Vertex.hpp"

void Vertex::connectTo(int end)
{
	edgeList.push_back(Edge(label, end, 1));
}

Vertex::Vertex(int lbl)
{
	label = lbl;
}