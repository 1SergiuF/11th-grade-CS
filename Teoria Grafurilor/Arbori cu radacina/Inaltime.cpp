#include <iostream>
#include <algorithm>
using namespace std;

const int N = 101;
int t[N];
int niv[N];
int n;
int niv_max = -1;

void Dfs(int x, int nv);

int main()
{
	int root = int();
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> t[i];
		if (t[i] == 0)
			root = i;
	}
	
	Dfs(root, 1);
	
	for (int i = 1; i <= n; ++i)
		niv_max = max(niv_max, niv[i]);
		
	cout << niv_max;
	
	return 0;
}

void Dfs(int x, int nv)
{
	niv[x] = nv;
	for (int f = 1; f <= n; ++f)
		if (t[f] == x)
			Dfs(f, nv + 1);
}
