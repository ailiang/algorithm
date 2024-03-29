#pragma once
#include <vector>
#include <set>

class DiWeightGraph;
class DiWeightEdge;

struct indexMin
{
	indexMin(int v, double weight);
	int _v;
	double _weight;
	bool operator< (const indexMin& i) const;
};

class dijkstra {
public:
	dijkstra(DiWeightGraph *g, int s);
	bool hasPath(int v);
	std::vector<DiWeightEdge> pathTo(int v);
	double disTo(int v);
private:
	std::vector<double> _dis;
	std::vector<DiWeightEdge> _path;
	std::set<indexMin> _pq;

	void relex(DiWeightGraph* g, int v);
};
