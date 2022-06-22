#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

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

bool readFile(const std::string& filename, edgeDataType t, std::vector<edgeDT> &out) {
	ifstream in;
	in.open(filename.c_str());
	if (!in.is_open()) {
		return false;
	}
	std::string line;
	edgeDT data;
	while (getline(in, line)) {
		std::istringstream iss(line);
		iss >> data.a >> data.b;
		if (t == EDT_3)
		{
			iss >> data.w;
		}
		out.push_back(data);
	}
	in.close();
	return true;
}
