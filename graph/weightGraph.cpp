#include "weightGraph.h"
#include <sstream> 
#include "reader.h"


WeightEdge::WeightEdge(int v, int w, double weight) :_v(v), _w(w), _weight(weight)
{
}

double WeightEdge::weight() const
{
	return _weight;
}

int WeightEdge::either() const
{
	return _v;
}

int WeightEdge::other(int v) const
{
	if (v == _v) return _w;
	else if (v == _w) return _v;
	return -1;
}

int WeightEdge::compareTo(const WeightEdge & e)
{
	if (_weight < e.weight()) return -1;
	else if (_weight > e.weight()) return 1;
	return 0;
}

std::string WeightEdge::toString()
{
	std::stringstream ss;
	ss << "v->w " << _v << "->" << _w << " weight:" << _weight;
	return ss.str();
}

WeightGraph::WeightGraph(const std::vector<edgeDT>& dt)
{
	_v = dt.size();
	_adjs.resize(_v);
	for (auto& e : dt)
	{
		addEdge(WeightEdge(e.a, e.b, e.w));
	}
}

void WeightGraph::addEdge(const WeightEdge & e)
{
	int v = e.either(), w = e.other(v);
	_adjs[v].push_back(e);
	_adjs[w].push_back(e);
	_e++;
}

std::vector<WeightEdge> WeightGraph::edges()
{
	std::vector<WeightEdge> ret;
	for (int i = 0; i < _v; i++)
	{
		for (auto& e : _adjs[i])
		{
			if (e.other(i) > i) {
				ret.push_back(e);
			}
		}
	}
	return ret;
}

std::vector<WeightEdge> WeightGraph::adj(int v)
{
	if (v < 0 || v >= _adjs.size())
	{
		return std::vector<WeightEdge>();
	}
	return _adjs[v];
}
