
#include <iostream>
#include "graph.h"
#include "digraph.h"
#include "reader.h"
#include "weightGraph.h"

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



int main()
{
	if (true)
	{
		std::cout << "graph: \n";
		std::vector<edgeDT> dt;
		int v = readFile("data/tinyG.txt", EDT_2, dt);
		Graph g(v, dt);
		std::cout << g.toString() << std::endl;
	} 

	if (true)
	{
		std::cout << "digraph: \n";
		std::vector<edgeDT> dt;
		int v = readFile("data/tinyDG.txt", EDT_2, dt);
		Digraph g(v, dt);
		std::cout << g.toString() << std::endl;
	}

	if (true)
	{
		std::cout << "EWgraph: \n";
		std::vector<edgeDT> dt;
		int v = readFile("data/tinyEWG.txt", EDT_3, dt);
		WeightGraph g(v, dt);
		std::cout << g.toString() << "\n";
	}

	std::cin.get();
    return 0;
}

