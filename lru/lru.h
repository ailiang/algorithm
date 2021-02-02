#include <list>
#include <map>
#include <string>
#include <iostream>
using namespace std;
template < typename K, typename V >
class LRU
{
public:
	LRU( size_t size ) : max_size( size )
	{
	}
	void set(const K& k, const V& v )
	{
		cout << "set:" << k << "->" << v << endl;
		auto it = _map.find( k );
		if( it != _map.end() )
		{
			_list.splice(_list.begin(), _list, it->second );
			_list.front().second = v;
			dump( "set");
			return ;
		}
		_list.emplace_front( k, v );
		_map.emplace( k, _list.begin() );
		if( _list.size() > max_size )
		{
			auto& data = _list.back();
			_map.erase( data.first );
			_list.pop_back();
		}
		dump( "set");
	}

	V get(const K& k)
	{
		cout << "get:" << k << endl;
		auto it = _map.find( k );
		if( it != _map.end() )
		{
			_list.splice( _list.begin(), _list, it->second );
			dump("get");
			return _list.front().second;
		}
		dump("get");
		return V();
	}
private:
	std::list<pair<K,V>>  _list;
	using data_itr = typename  std::list<pair<K, V>>::iterator;
	std::map<K, data_itr> _map;
	size_t max_size;

	void dump( const std::string& str )
	{
		cout << "list data:\t";
		for( auto& v: _list )
		{
			cout << v.first << "->" << v.second << "\t";
		}
		cout << endl;

		cout << "map data:\t";
		for( auto& v: _map )
		{
			cout << v.first << "->(" << v.second->first << "," << v.second->second << ")\t";
		}
		cout << endl << endl;
	}
};
