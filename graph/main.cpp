
#include <iostream>
#include "graph.h"
#include "digraph.h"
#include "reader.h"
#include "weightGraph.h"
#include "primMst.h"
#include "diWeightGraph.h"
#include "dijkstra.h"

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
	if (false)
	{
		std::cout << "graph: \n";
		std::vector<edgeDT> dt;
		int v = readFile("data/tinyG.txt", EDT_2, dt);
		Graph g(v, dt);
		std::cout << g.toString() << std::endl;
	} 

	if (false)
	{
		std::cout << "digraph: \n";
		std::vector<edgeDT> dt;
		int v = readFile("data/tinyDG.txt", EDT_2, dt);
		Digraph g(v, dt);
		std::cout << g.toString() << std::endl;
	}

	if (false)
	{
		std::cout << "EWgraph: \n";
		std::vector<edgeDT> dt;
		int v = readFile("data/tinyEWG.txt", EDT_3, dt);
		WeightGraph g(v, dt);
		std::cout << g.toString() << "\n";
		PrimMst mst(&g);
		std::cout << mst.toString() << std::endl;
	}

	if (true)
	{
		std::cout << "EWD: \n";
		std::vector<edgeDT> dt;
		int v = readFile("data/tinyEWD.txt", EDT_3, dt);
		DiWeightGraph g(v, dt);
		std::cout << g.toString() << "\n";

		dijkstra dijk(&g, 0);
		for (int i = 0; i < v; i++)
		{
			std::cout << "v:" << i << " dis:" << dijk.disTo(i) << "\n";
		}

		std::stringstream ss;
		for (int i = 0 ; i < v; i++)
		{
			ss << "v: " << i << " path: ";
			auto path = dijk.pathTo(i);
			for (auto& e: path)
			{
				ss << "->" << e.from();
			}
			ss << "\n";
		}
		std::cout << ss.str();
		
	}


	std::cin.get();
    return 0;
}

