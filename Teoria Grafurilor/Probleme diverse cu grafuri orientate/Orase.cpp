#include <iostream>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

VI G[101];
VB v, os, sol;
int n, m, k, ov;

void CitesteGraf();
void Bfs(int p, int q);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	CitesteGraf();
	
	for (int i = 1; i <= ov; ++i)
		(sol[i])
			? cout << "DA\n"
			: cout << "NU\n";
			
	return 0;
}

void Bfs(int p, int q)
{
	v = VB(n + 1, false);
	queue<int> Q;
	v[p] = true;
	Q.push(p);
	
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		
		for (auto const& y : G[p])
			if (!v[y] && (os[y] || y == q))
			{
				v[y] = true;
				Q.push(y);
			}
	}
}

void CitesteGraf()
{
	cin >> n >> m >> k >> ov;
	sol = VB(ov + 1);
	os  = VB(n + 1);
	for (int i = 1, x, y; i <= m; ++i)
	{
		cin >> x >> y;
		G[x].pb(y);
	}
	
	for (int i = 1, x; i <= k; ++i)
	{
		cin >> x;
		os[x] = true;
	}
	
	for (int i = 1, x, y; i <= ov; ++i)
	{
		cin >> x >> y;
		Bfs(x, y);
		v[y] ? sol[i] = true : sol[i] = false;
	}
}
