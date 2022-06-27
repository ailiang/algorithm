#include "primMst.h"
#include "weightGraph.h"
#include <sstream>

PrimMst::PrimMst(WeightGraph * g)
{
	auto v = g->V();
	_marked.resize(v);
	visit(g, 0);
	while (!_pq.empty())
	{
		auto minEdge = _pq.top();
		_pq.pop();
		int v = minEdge.either(), w = minEdge.other(v);
		if (_marked[v] && _marked[w] )
		{
			continue;
		}
		_mst.push_back(minEdge);
		if (!_marked[v]) visit(g, v);
		if (!_marked[w]) visit(g, w);
	}
}

void PrimMst::visit(WeightGraph * g, int v)
{
	_marked[v] = true;
	auto& vec = g->adj(v);
	for (auto& e: vec)
	{
		if (!_marked[e.other(v)])
		{
			_pq.push(e);
		}
	}
	
}

std::string PrimMst::toString()
{
	std::stringstream ss;
	for (auto e: _mst)
	{
		int v = e.either(), w = e.other(v);
		double weight = e.weight();
		ss << v << " " << w << " " << weight << "\n";
	}
	return ss.str();
}
