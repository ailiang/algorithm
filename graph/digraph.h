#pragma once

#include <vector>
#include <map>
#include <string>
#include "reader.h"

class Digraph {
public:
	Digraph(int v, const std::vector<edgeDT>& dts);

	int V() { return  _vNum; }
	int E() { return _eNum; }
	void addEdge(int v, int w);
	std::vector<int> adj(int v);
	std::string toString();
	
private:
	int _vNum;
	int _eNum;
	std::vector<std::vector<int>> _adjs;
};

class DiSearch {
public:
	DiSearch(Digraph* g, int v);
	DiSearch(Digraph* g, const std::vector<int>& vv);
	bool marked(int v);
private:
	std::vector<bool> _marked;
	void dfs(Digraph* g, int v);
};

class DiCycle {
public:

	DiCycle(Digraph* g);
	bool hasCycle();
	std::vector<int> cycle();
private:
	void dfs(Digraph* g, int v);
};
