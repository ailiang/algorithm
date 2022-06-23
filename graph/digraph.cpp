#include "digraph.h"
#include  <sstream>

Digraph::Digraph(int v, const std::vector<edgeDT>& dts): _vNum(v), _eNum(0)
{
	_adjs.resize(_vNum);
	for (auto& e: dts)
	{
		addEdge(e.a, e.b);
	}
}

void Digraph::addEdge(int v, int w)
{
	_adjs[v].push_back(w);
	_eNum++;
}

std::vector<int> Digraph::adj(int v)
{
	if (v < 0 || v >= _vNum)
	{
		return std::vector<int>();
	}
	return _adjs[v];
}

std::string Digraph::toString()
{
	std::stringstream ss;
	ss << " V: " << _vNum << " E:" << _eNum << " \n";
	for (int v = 0; v < _vNum; ++v)
	{
		ss << v << "  adj: ";
		for (auto& w: adj(v) )
		{
			ss << w << ",";
		}
		ss << std::endl;
	}
	return ss.str();
}

DiSearch::DiSearch(Digraph * g, int v): _marked(g->V())
{
	for (auto i = 0; i < (int)_marked.size(); ++i)
	{
		_marked[i] = false;
	}
	dfs(g, v);
}

DiSearch::DiSearch(Digraph * g, const std::vector<int>& vv): _marked(g->V())
{
	for (auto& v: vv)
	{
		if (!marked(v))
		{
			dfs(g, v);
		}
	}
}

bool DiSearch::marked(int v)
{
	return _marked[v];
}

void DiSearch::dfs(Digraph* g, int v)
{
	_marked[v] = true;
	for (auto& w: g->adj(v))
	{
		if (!marked(w))
		{
			dfs(g, w);
		}
	}
}

DiCycle::DiCycle(Digraph * g)
{
}

bool DiCycle::hasCycle()
{
	return false;
}

std::vector<int> DiCycle::cycle()
{
	return std::vector<int>();
}

void DiCycle::dfs(Digraph* g, int v)
{

}
