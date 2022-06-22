
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
	if (false)
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
	} 

	if (false)
	{
		Digraph g(13);
		std::cout << g.toString() << std::endl;

		DiSearch s(&g, 0);
		std::cout <<  "0->8" << " : " << s.marked(9) << std::endl;

		std::vector<int> vv;
		vv.push_back(0);
		vv.push_back(6);
		DiSearch s1(&g, vv);
		std::cout <<  "0, 6->8" << " : " << s1.marked(9) << std::endl;
	}

	if (true)
	{
		std::string filename("data/tinyEWG.txt");
		std::vector<edgeDT> dt;
		readFile(filename, EDT_3, dt);
		WeightGraph g(dt);
		auto edges = g.edges();
		for (auto& e: edges)
		{
			std::cout << e.toString() << "\n";
		}
				
	}

	std::cin.get();
    return 0;
}

