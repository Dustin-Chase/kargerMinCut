#include "stdafx.h"
#include "Weighted_UF.h"


Weighted_UF::Weighted_UF(int N) : count(N), sz(N + 1, 1)
{ 
	for (int i = 0; i <= N; ++i) id.push_back(i);
}

int Weighted_UF::getCount()
{
	return count; 
}

bool Weighted_UF::connected(int p, int q)
{
	return find(p) == find(q);
}

int Weighted_UF::find(int p)
{
	while (p != id[p]) p = id[p];
	return p;
}

void Weighted_UF::wfUnion(int p, int q)
{
	int i = find(p);
	int j = find(q);

	if (i == j) return; 

	//make smaller root point to larger one
	if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
	else			   { id[j] = i; sz[i] += sz[j]; }
	count--;
}

int Weighted_UF::getMax()
{
	return *std::max_element(sz.begin(), sz.end());
}
