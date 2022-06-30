#include "dijkstra.h"
#include "diWeightGraph.h"

dijkstra::dijkstra(DiWeightGraph * g, int s)
{
	_dis.resize(g->V());
	_path.resize(g->V());
	for (int i = 0; i < g->V(); i++)
	{
		_dis[i] = INT_MAX;
	}
	_dis[s] = 0;
	_pq.emplace(s, 0);
	while (!_pq.empty())
	{
		auto v = *_pq.begin();
		_pq.erase(_pq.begin());
		relex(g, v._v);
	}
}

bool dijkstra::hasPath(int v)
{
	return _dis[v] < INT_MAX;
}

std::vector<DiWeightEdge> dijkstra::pathTo(int v)
{
	std::vector<DiWeightEdge> ret;
	for (auto e = _path[v]; e.from() >= 0; e = _path[e.from()] )
	{
		ret.push_back(e);
	}
	return ret;
}

double dijkstra::disTo(int v)
{
	return _dis[v];
}

void dijkstra::relex(DiWeightGraph * g, int v)
{
	auto vec = g->adj(v);
	for (auto& e : vec)
	{
		int w = e.to();
		if (disTo(v) + e.weight() < disTo(w))
		{
			_path[w] = e;
			_dis[w] = e.weight() + _dis[v];
			for (auto it = _pq.begin(); it != _pq.end(); it++)
			{
				if (it->_v  == w)
				{
					_pq.erase(it);
					break;
				}
			}
			_pq.emplace(w, _dis[w]);
		}
	}
}

indexMin::indexMin(int v, double weight): _v(v), _weight(weight)
{
}

bool indexMin::operator<(const indexMin & i) const
{
	return i._weight < _weight;
}
