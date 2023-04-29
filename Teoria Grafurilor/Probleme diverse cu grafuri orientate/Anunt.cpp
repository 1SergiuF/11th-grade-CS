#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;

VVI G;
VB v;
VI d;
int n, m;

void CitesteGraf();
void Bfs(int x);

int main()
{
	CitesteGraf();
	
	for (int i = 1; i <= n; ++i)
	{
		Bfs(i);
		bool ok = true;
		for (int j = 1; j <= n; ++j)
			if (!d[j] && i != j)
			{
				ok = false;
				break;
			}
			
		if (ok) cout << i << ' ';
	}
	
	return 0;
}

void Bfs(int x)
{
	d = VI(n + 1, 0);
	v = VB(n + 1, false);
	queue<int> Q;
	v[x] = true;
	Q.push(x);
	
	while (!Q.empty())
	{
		x = Q.front();
		Q.pop();
		
		for (auto const& y : G[x])
		{
			if (v[y]) continue;
			v[y] = true;
			d[y] = d[x] + 1;
			Q.push(y);
		}
	}
}

void CitesteGraf()
{
	cin >> n >> m;
	G = VVI(n + 1);
	v = VB(n + 1);
	
	int x, y;
	for (int e = 1; e <= m; ++e)
	{
		cin >> x >> y;
		G[x].emplace_back(y);
	}
}
