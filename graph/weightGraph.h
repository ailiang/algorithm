#pragma once

#include <string> 
#include <vector>

class WeightEdge {
public:
	WeightEdge(int v, int w, double weight);
	double weight() const;
	int either() const;
	int other(int v) const;
	int compareTo(const WeightEdge&);
	std::string toString();
	bool operator<(const WeightEdge& e) const;
private:
	int _v, _w;
	double _weight;
};

struct edgeDT;

class WeightGraph {
public:
	WeightGraph(int v, const std::vector<edgeDT>& dt );
	int V() {return _v;};
	int E() { return _e; }
	void addEdge(const WeightEdge& e);
	std::vector<WeightEdge> edges();
	std::vector<WeightEdge> adj(int v);
	std::string toString();
private:
	std::vector<std::vector<WeightEdge>> _adjs;
	int _v, _e;
};
