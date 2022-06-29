#include "diWeightGraph.h"
#include "reader.h"
#include <sstream>

DiWeightEdge::DiWeightEdge(int v, int w, double weight): _v(v), _w(w),_weight(weight)
{

}

DiWeightEdge::DiWeightEdge():_v(-1),_w(-1),_weight(-1)
{
}

int DiWeightEdge::from() const
{
	return _v;
}

int DiWeightEdge::to() const
{
	return _w;
}

double DiWeightEdge::weight() const
{
	return _weight;
}

bool DiWeightEdge::operator<(const DiWeightEdge & e)
{
	return e.weight() < _weight;
}

DiWeightGraph::DiWeightGraph(int v, const std::vector<edgeDT>& dt) :_v(v),_e(0)
{
	_adjs.resize(v);
	for (auto& d: dt)
	{
		addEdge(DiWeightEdge(d.a, d.b, d.w));
	}
}

void DiWeightGraph::addEdge(const DiWeightEdge& e)
{
	_adjs[e.from()].push_back(e);
	_e++;
}

int DiWeightGraph::V()
{
	return _v;
}

int DiWeightGraph::E()
{
	return _e;
}

std::vector<DiWeightEdge> DiWeightGraph::adj(int v)
{
	return _adjs[v];
}

std::string DiWeightGraph::toString()
{
	std::stringstream ss;
	ss << _v << " " << _e << "\n";
	for (int i = 0; i < _v; i++)
	{
		auto vec = adj(i);
		ss << i << " adj:  ";
		for (auto& w: vec)
		{
			ss << w.to() << " " << w.weight() << " |";
		}
		ss << std::endl;
	}
	return ss.str();
}
