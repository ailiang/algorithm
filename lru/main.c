#include "lru.h"

int main()
{
	LRU<int,int> lru(3);
	while( 1 )
	{
		int op, k, v;
		cin >> op;
		cin >> k;
		if( op == 0 )
		{
			cin >> v;
			lru.set(k,v);
		}
		else
		{
			lru.get(k);
		}
	}
	return 0;
}
