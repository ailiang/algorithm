
#include <iostream>
#include "graph.h"

const static int NUM_V = 13;
const static int NUM_E = 13;

char edgeData[][2] = {
	{0,5},
	{4,3},
	{0,1},
	{9,12},
	{6,4},
	{5,4},
	{0,2},
	{11,12},
	{9,10},
	{0,6},
	{7,8},
	{9,11},
	{5,3},
};

int degree(Graph* g, int v) {
	auto vec = g->adj(v);
	return vec.size();
}


int main()
{
	Graph g;
	g.buildGraph(NUM_V, edgeData);
	std::cout << g.toString();

	std::stringstream ss;
	ss << " 0 link with: ";
	Search s(&g, 0);
	for (int i = 0; i < g.V(); i++)
	{
		if (s.marked(i))
		{
			ss << " ";
			ss << i;
		}
	}
		
	std::cout << ss.str() << std::endl; 
	std::cin.get();
    return 0;
}

