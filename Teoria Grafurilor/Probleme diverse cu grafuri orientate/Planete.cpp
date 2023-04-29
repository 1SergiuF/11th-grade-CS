#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<VI> VVI;

VB v;
VI data;
VVI G;
int n;
int cnt;

inline void Dfs(int x);

int main()
{
	cin >> n;
	
	G    = VVI(n + 1);
	data = VI(n + 1);
	
	int x;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		data[i] = x;
	}
	
	for (int i = 1; i <= n; ++i)
		G[i].push_back(data[data[i]]);
		
	
	for (int i = 1; i <= n; ++i)
	{
		cnt = 0;
		v = VB(n + 1);
		Dfs(i);
	}
		
	return 0;
}

inline void Dfs(int x)
{
	if (v[x])
	{
		cout << cnt << ' ';
		return;
	}
	
	v[x] = true;
	for (auto const& y : G[x])
	{
		++cnt;
		Dfs(y);
	}
}
