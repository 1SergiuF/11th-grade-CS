#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef VI::reverse_iterator RIT;

VVI G;
VB v;
VI sort_top;
int n, m;

void CitesteGraf();
void Dfs(int x);
void SortTop();

int main()
{
	CitesteGraf();
	SortTop();
	
	int cnt = 0;
	for (RIT it = sort_top.rbegin(); it != sort_top.rend(); ++it)
	{
		if (find(begin(G[*it]), end(G[*it]), *(it + 1) == end(G[*it])))
			continue;
		++cnt;
	}
			
	cout << cnt;
	return 0;
}

void SortTop()
{
	v = VB(n + 1, false);
	for (int nod = 1; nod <= n; ++nod)
		if (!v[nod])
			Dfs(nod);
}

void Dfs(int x)
{
	v[x] = true;
	for (int const& y : G[x])
		if (!v[y])
			Dfs(y);
			
	sort_top.emplace_back(x);
}

void CitesteGraf()
{
	cin >> n >> m;
	G = VVI(n + 1);
	
	int x, y;
	while (m--)
	{
		cin >> x >> y;
		G[x].emplace_back(y);
	}
}
