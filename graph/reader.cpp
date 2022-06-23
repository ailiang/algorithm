
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "reader.h"

using namespace std;

int readFile(const std::string& filename, edgeDataType t, std::vector<edgeDT> &out) {
	ifstream in;
	int v = 0;
	in.open(filename.c_str());
	if (!in.is_open()) {
		return false;
	}
	std::string line;
	getline(in, line);
	std::istringstream ss(line);
	ss >> v;
	getline(in, line);
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
	return v;
}
