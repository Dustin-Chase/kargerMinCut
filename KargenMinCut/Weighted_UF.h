#pragma once
#include "stdafx.h"
/*
Implementation of Weighted Quick Union as described in Algorithms (Sedgewick and Wayne)
*/

class Weighted_UF
{

private: 
	std::vector<int> id;   //parent link (site indexed) 
	std::vector<int> sz;   //size of component for roots
	int count;             //number of components
public:
	Weighted_UF(int N);
	
	//return number of components
	int getCount();
	
	//true if p and q are in the same component, false otherwise
	bool connected(int p, int q);
	
	//find which component p is in
	int find(int p);

	//create union of components p and q
	void wfUnion(int p, int q);

	//get largest element in sz
	int getMax();

};

