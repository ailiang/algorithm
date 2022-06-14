
#include "graph.h"
#include <iostream>
#include <list> 

Graph::Graph(): _v(0), _e(0)
{
}


Graph::~Graph()
{
}

void Graph::buildGraph(int V,  char data[][2])
{
	_v = V;
	for (int i = 0; i < V; ++i)
	{
		addEdge(data[i][0], data[i][1]);
	}
}

int Graph::V() const
{
	return _v;
}

int Graph::E() const
{
	return _e;
}

void Graph::addEdge(int from, int to)
{
	_adj[from].push_back(to);
	_adj[to].push_back(from);
	_e++;
}

std::vector<int> Graph::adj(int v)
{
	auto it = _adj.find(v);
	if (it != _adj.end()) {
		return it->second;
	}
	return std::vector<int>();
}

std::string Graph::toString() 
{
	std::stringstream s;
	s << _v;
	s << " vertex ";
	s << _e;
	s << " edge \n";
	for (int i = 0; i < V(); i++ )
	{
		auto vec = adj(i);
		s << i;
		s << " :";
		for (int j = 0; j < int(vec.size()); ++j )
		{
			s << " ";
			s << vec[j];
		}
		s << "\n";
	}
	return s.str();
}

Search::Search(Graph * g, int v)
{
	dfs(g, v);
}

bool Search::marked(int v)
{
	return _linkd.find(v) != _linkd.end();
}

void Search::dfs(Graph * g, int v)
{
	connect(v);
	auto adj = g->adj(v);
	for (auto& m : adj)
	{
		if (!marked(m))
		{
			dfs(g, m);
		}
	}
}

void Search::connect(int v)
{
	_linkd.emplace(v);
}

Pathto::Pathto(Graph * g, int start)
{
	_start = start;
	bfs(g, start);
}



bool Pathto::hasPath(int v)
{
	auto it = path.find(v);
	if (it == path.end()) {
		return false;
	}
	int prev = it->second;
	while (prev != _start) {
		auto it = path.find(v);
		if (it == path.end()) {
			break;
		}
		prev = it->second;
	}
	return prev == _start;
}

void Pathto::bfs(Graph * g, int v)
{
	std::list<int> l;
	l.push_back(v);
	markd.emplace(v);
	while (!l.empty())
	{
		int k = l.front();
		l.pop_front();
		for (auto& i : g->adj(k))
		{
			if (!markd.count(i))
			{
				l.push_back(i);
				path[i] = k;
				markd.emplace(i);
			}
		}
	}
}
