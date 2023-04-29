#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int N = 101;
int t[N];
int niv[N];
int n, k;
set<int> noduri;

void Dfs(int x, int nv);

int main()
{
	int root = int();
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> t[i];
		if (t[i] == 0)
			root = i;
	}
	
	Dfs(root, 1);
	
	for (int const& val : noduri)
		cout << val << ' ';
		
	return 0;
}

void Dfs(int x, int nv)
{
	niv[x] = nv;
	if (niv[x] == k) noduri.insert(x);
	for (int f = 1; f <= n; ++f)
		if (t[f] == x)
			Dfs(f, nv + 1);
}

