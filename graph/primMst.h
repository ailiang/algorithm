#pragma once

#include <vector>
#include <queue>
#include <string>

class WeightGraph;
class WeightEdge;

class PrimMst {
public:
	PrimMst(WeightGraph* g);
	void visit(WeightGraph* g, int v);
	std::string toString();
private:
	std::vector<int> _marked;
	std::vector<WeightEdge> _mst;
	std::priority_queue<WeightEdge> _pq;
};
