#include "graph.h"

Graph::Graph()
{
	vertices = nullptr;
}
// Graph()
// Constructor initializes vertices linked list to empty

void Graph::AddVertex(string v) 
{

	if (vertices == nullptr)
	{
		VertexNode *temp = new VertexNode;
		temp->vname = v;
		temp->nextVertex = nullptr;
		temp->edgePtr = nullptr;
		temp->mark = false;
		vertices=temp;
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
	VertexNode *svertex = VertexExists(s);
	VertexNode *dvertex = VertexExists(d);
	EdgeNode *newEdge = new EdgeNode;
	EdgeNode *traverse = svertex->edgePtr;
	if (svertex->edgePtr == nullptr)
	{	
		newEdge->destination = dvertex;
		newEdge->weight = w;
		newEdge->nextEdge = nullptr;
		svertex->edgePtr = newEdge;
	}
	else
	{
		while (traverse->nextEdge != nullptr)
		{
			traverse = traverse->nextEdge;
		}
		newEdge->destination = dvertex;
		newEdge->weight = w;
		newEdge->nextEdge = nullptr;
		traverse->nextEdge = newEdge;
	}
	
}

// AddEdge()
// Adds edge from source S  to destination D with specified weight W.
// If there is not enough memory to add the edge, throw the GraphFull exception

VertexNode* Graph::VertexExists(string v) const
{
	VertexNode *temp = vertices;
	while(temp!= nullptr)
	{
		if(temp->vname ==v)
		{
			return temp;
		}
		temp=temp->nextVertex;
	}
	return NULL;
}
// VertexExists()
// Returns pointer to corresponding VertexNode if vertex V in graph 
// Returns NULL otherwise


EdgeNode* Graph::EdgeExists(string s, string d) const
{
	VertexNode *svertex = VertexExists(s);
	VertexNode *dvertex = VertexExists(d);
	if(svertex != NULL && dvertex !=NULL)
	{
		EdgeNode *edge = svertex->edgePtr;
		while(edge!=nullptr)
		{
			if(edge->destination == dvertex)
			{
				return edge;
			}
			edge = edge->nextEdge;
		}
	}
	return NULL;
}
// EdgeExists()
// Returns pointer to edge node if edge from vertex s to vertex d exists in graph 
// Returns NULL otherwise

int  Graph::WeightIs(string s, string d)
{
	EdgeNode *temp = EdgeExists(s, d);
	if (temp == NULL)
	{
		throw GraphEdgeNotFound();
	}
	return temp->weight;
}
// WeightIs()
// Returns weight of edge (s,d).  Throws GraphEdgeNotFound if edge not present.

void Graph::ClearMarks()
{
	VertexNode *traverse = vertices;
	while (traverse->nextVertex != nullptr)
	{
		traverse->mark = false;
		traverse = traverse->nextVertex;
	}
}
// ClearMarks()
// Clears all vertex marks

void Graph::MarkVertex(string v)
{
	VertexNode *temp = VertexExists(v);
	if (temp != NULL)
	{
		temp->mark = true;
	}
	else 
	{
		throw GraphVertexNotFound();
	}
}
// MarkVertex()
// Marks vertex V as visited
// Throws GraphVertexNotFound if not present

bool Graph::IsMarked(string v)
{
	VertexNode *temp= VertexExists(v);
	if (temp != NULL)
	{
		if (temp->mark)
		{
			return true;
		}
		return false;
	}
	else
	{
		throw GraphVertexNotFound();
	}
}
// IsMarked()
// Returns true if vertex V is marked, false if not marked
// Throws GraphVertexNotFound if not present

void Graph::GetToVertices(string V, queue<string>& q)
{
	VertexNode *target = VertexExists(V);
	if (target !=NULL)
	{
		EdgeNode *traverse = target->edgePtr;
		while (traverse != nullptr)
		{
			q.push(traverse->destination->vname);
			traverse = traverse->nextEdge;
		}
	}
	else
	{
		throw GraphVertexNotFound();
	}
}
// GetToVertices()
// Returns queue Q of vertex names of those vertices adjacent to vertex V
// The queue here is from the Standard Template Library
// Throws GraphVertexNotFound if not present

void Graph::DepthFirstSearch(string startVertex, string endVertex, queue<string>& path)
{
	VertexNode *start = VertexExists(startVertex);
	MarkVertex(startVertex);
	queue<string> adjq;
	stack<string> searchs;
	GetToVertices(startVertex, adjq);
	for (int i = 0; i < adjq.size(); i++)
	{
		searchs.push(adjq.front);
		adjq.pop();
		adjq.
	}
	while (!searchs.empty())
	{
		if(!IsMarked(searchs.top())
		{
			MarkVertex(searchs.top());
			path.push(searchs.top());
			searchs.pop();
			GetToVertices(searchs.top(), adjq);
			for (int i = 0; i < adjq.size(); i++)
			{
				searchs.push(adjq.front());
				adjq.pop();
			}
		}
	}
}
// DepthFirstSearch()
// Notes:
// (1) This algorithm is flawed in that as it searches for a path, it may
// output some additional vertices that it visited but were not part
// of the actual path.  
// 
// (2) This algorithm requires use of the stack and queue containers from the
// Standard Template Library.  

void Graph::BreadthFirstSearch(string startVertex, string endVertex, queue<string>& visitedq)
{

}
// BreadthFirstSearch()
// Uses the BFS algorithm to determine a path from the
// startVertex to the endVertex.  If a path is found, the path vertices should
// be in the visited queue.  If no path is found, the visited queue should be emptied
// as a signal to the client code that no path exists between the start and
// end vertices.

Graph::~Graph()
{
	VertexNode *current = vertices;
	VertexNode *deletion = new VertexNode;
	vertices = nullptr;
	while(current!=nullptr)
	{
		deletion = current;
		current = current->nextVertex;
		delete deletion;
	}
		

}
// ~Graph()
// For each VertexNode in the vertices list, Destrucot deallocates all EdgeNodes before 
// deallocating the VertexNode itself