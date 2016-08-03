#pragma once
#include "stdafx.h"
class Graph
{
private: 
	struct Edge {
		int src, dest;
		Edge();
		Edge(int src, int dest);
	};
	std::vector<Edge> edges;
	int V; //number of vertices
	int E; //number of edges
public:
	Graph();
	Graph(int num_vert);
	Graph(int num_vert, int num_edges);
	int getNumVert();
	int getNumEdges();
	void addEdge(int src, int dest); 
	Edge getEdge(int index);
	void printEdges(int vertex);
};

