#pragma once

#include <vector>


struct edgeDT 
{
	edgeDT():a(0),b(0),w(0.0) {}
	int a;
	int b;
	double w;
};

enum edgeDataType 
{
	EDT_2 = 0,
	EDT_3 = 1,
};

bool readFile(const std::string& filename, edgeDataType t, std::vector<edgeDT> &out);
