#include "digraph.h"
#include  <sstream>

static const int digraphData[][2] = {
	{4,2},
	{2,3},
	{3,2},
	{6,0},
	{0,1},
	{2,0},
	{11,12},
	{12,9},
	{9,10},
	{9,11},
	{8,9},
	{10,12},
	{11,4},
	{4,3},
	{3,5},
	{7,8},
	{8,7},
	{5,4},
	{0,5},
	{6,4},
	{6,9},
	{7,6},
};

Digraph::Digraph(int vNum) :_vNum(vNum), _eNum(0), _adjs(_vNum)
{
	int n = sizeof(digraphData) / sizeof(digraphData[0]);
	for (int i = 0; i < n; ++i)
	{
		addEdge(digraphData[i][0], digraphData[i][1]);
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

Digraph * Digraph::reverse()
{
	Digraph* r = new Digraph(V());
	for (int v = 0; v < r->V(); v++)
	{
		for (auto& w : adj(v))
		{
			r->addEdge(w, v);
		}
	}
	return r;
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
	for (auto i = 0; i < _marked.size(); ++i)
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
