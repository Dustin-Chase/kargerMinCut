#include "stdafx.h"
#include "Graph.h"


Graph::Graph() : V(1), E(0) {}

Graph::Graph(int num_vert) : V(num_vert), E(0) {}

Graph::Graph(int num_vert, int num_edges) : V(num_vert), E(num_edges),
											edges(num_edges) {}

int Graph::getNumVert()
{
	return V;
}

int Graph::getNumEdges()
{
	return E;
}

void Graph::addEdge(int src, int dest)
{
	edges.push_back({src, dest});
	E++; 
}

Graph::Edge Graph::getEdge(int index)
{
	return edges[index];
}

void Graph::printEdges(int vertex)
{
	for (std::vector<Edge>::iterator iter = edges.begin(); iter != edges.end(); iter++) {
		if (iter->src == vertex) {
			std::cout << iter->src << " -> " << iter->dest << '\n';
		}
	}
}

Graph::Edge::Edge() : src(0), dest(0) {}

Graph::Edge::Edge(int src, int dest) : src(src), dest(dest) {}
