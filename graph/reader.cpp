
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "reader.h"

using namespace std;

bool readFile(const std::string& filename, edgeDataType t, std::vector<edgeDT> &out) {
	ifstream in;
	in.open(filename.c_str());
	if (!in.is_open()) {
		return false;
	}
	std::string line;
	getline(in, line);
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
	return true;
}
