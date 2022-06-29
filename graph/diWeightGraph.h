#pragma once
#include <vector>
#include <string>
struct edgeDT;
class DiWeightEdge {
public:
	DiWeightEdge(int v, int w, double weight);
	DiWeightEdge();
	int from() const;
	int to() const;
	double weight() const;
	bool operator<(const DiWeightEdge& e);
private:
	int _v, _w;
	double _weight;
};

class DiWeightGraph {
public:
	DiWeightGraph(int v, const std::vector<edgeDT>& dt);
	void addEdge(const DiWeightEdge& e);
	int V();
	int E();
	std::vector<DiWeightEdge> adj(int v);
	std::string toString();
private:
	int _v, _e;
	std::vector<std::vector<DiWeightEdge>> _adjs;
};
