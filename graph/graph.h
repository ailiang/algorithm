#pragma once

#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <set>


class Graph
{
public:
	Graph();
	~Graph();

	void buildGraph(int V, char data[][2]);

	int V() const;
	int E() const;
	void addEdge(int from, int to);
	std::vector<int> adj(int v);
	std::string toString();
private:
	int _v, _e;
	std::map<int, std::vector<int>> _adj;
};

class Search {
public:
	Search(Graph* g, int v);
	bool marked(int v);
private:
	std::set<int> _linkd;
	void dfs(Graph* g, int v);
	void connect(int v);
};

class Pathto {
public:
	Pathto(Graph* g, int start);
	bool hasPath(int v);
private:
	std::set<int> markd;
	std::map<int, int> path;

	int _start;

	void bfs(Graph* g, int v);
};

