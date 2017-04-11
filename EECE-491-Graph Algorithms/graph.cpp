#include "graph.h"

Graph::Graph()
{
	vertices = nullptr;
	queue q;
}
// Graph()
// Constructor initializes vertices linked list to empty

void Graph::AddVertex(string v) 
{
	if (vertices == nullptr)
	{
		vertices->vname = v;
		vertices->nextVertex = nullptr;
		vertices->edgePtr = nullptr;
		vertices->mark = false;
	}
	else
	{
		VertexNode *temp = vertices;
		VertexNode *newVertex = new VertexNode;
		while (temp->nextVertex != nullptr)
		{
			temp = temp->nextVertex;
		}
		newVertex->vname = v;
		temp->nextVertex = newVertex;
		newVertex->nextVertex = nullptr;
		newVertex->edgePtr = nullptr;
		newVertex->mark = false;
	}
}
// AddVertex()
// Adds vertex to graph assuming vertex not already present

void Graph::AddEdge(string s, string d, int w)
{
	VertexNode *svertice = VertexExists(s);
	EdgeNode *newEdge = new EdgeNode;
	EdgeNode *traverse = svertice->edgePtr;
	if (svertice->edgePtr == nullptr)
	{
		svertice->edgePtr->destination = d;
		svertice->edgePtr->weight = w;
		svertice->edgePtr->nextEdge = nullptr;
	}
	else
	{
		while (traverse->nextEdge != nullptr)
		{
			traverse = traverse->nextEdge;
		}
		newEdge->destination = d;
		newEdge->weight = w;
		newEdge->nextEdge = nullptr;
		traverse->nextEdge = newEdge;
	}
	
}
// AddEdge()
// Adds edge from source S  to destination D with specified weight W.
// If there is not enough memory to add the edge, throw the GraphFull exception

VertexNode* VertexExists(string v) const
{
	VertexNode *temp = vertices;
	while (temp->vname != v || temp == nullptr)
	{
		temp = temp->nextVertex;
	}
	if (temp == nullptr)
	{
		return NULL;
	}
	return temp;
}
// VertexExists()
// Returns pointer to corresponding VertexNode if vertex V in graph 
// Returns NULL otherwise
