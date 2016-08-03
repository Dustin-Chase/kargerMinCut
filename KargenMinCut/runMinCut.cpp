
#include "stdafx.h"
#include "Graph.h"
#include "Weighted_UF.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm> 

int kargerMinCut(Graph& graph) {
	Weighted_UF uf(graph.getNumVert());

	while (uf.getCount() > 2) {
		int randEdge = rand() % graph.getNumEdges();
		int src = graph.getEdge(randEdge).src;
		int dest = graph.getEdge(randEdge).dest;
		int comp1 = uf.find(src);
		int comp2 = uf.find(dest);
		if (comp1 == comp2) continue; //if same component, skip this edge
		else {
			uf.wfUnion(src, dest);
		}

	}
	int cutedges = 0;
	for (int i = 0; i<graph.getNumEdges(); i++)
	{
		int subset1 = uf.find(graph.getEdge(i).src);
		int subset2 = uf.find(graph.getEdge(i).dest);
		if (subset1 != subset2)
			cutedges++;
	}

	return cutedges;
}


int main() {
	srand(time(NULL));
	constexpr int SIZE = 200; 
	constexpr int TIMES = 50; //number of times to run Karger's
	int min = 200; 
	Graph cutGraph(SIZE);
	std::ifstream graphData; 
	graphData.open("kargerMinCut.txt");
	if (!graphData) {
		std::cout << "Could not open that file!\n"; 
		return 1; 
	}
	std::string line; 
	std::cout << "Building graph..\n";
	//build the graph
	while (std::getline(graphData, line)) {
		std::istringstream iss(line);
		int src, dest;
		iss >> src; 
		while (iss >> dest) {
			if (dest > src) {
				cutGraph.addEdge(src, dest);
			}
		}
	}
	graphData.close();
	std::cout << "Running kargerMinCut " << TIMES << " times." << '\n';
	for (int i = 0; i < TIMES; i++) {
		int ans = kargerMinCut(cutGraph);
		if (ans < min) min = ans; 
	}
	std::cout << "\nCut found by Karger's randomized algorithm is " << min << '\n';
	return 0; 
}