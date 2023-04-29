#include <iostream>
using namespace std;

const int N = 101;
bool a[N][N];
bool v[N];
int t[N];
int n, k;

void CitesteGraf();
void Dfs(int x);

int main()
{
	CitesteGraf();
	t[k] = 0;
	Dfs(k);
	
	for (int i = 1; i <= n; ++i)
		cout << t[i] << ' ';
		
	return 0;
}

void Dfs(int x)
{
	v[x] = true;
	for (int y = 1; y <= n; ++y)
		if (a[x][y] && !v[y])
		{
			t[y] = x;
			Dfs(y);
		}
}
void CitesteGraf()
{
	cin >> n >> k;
	int x, y;
	for (int i = 1; i <= n - 1; ++i)
	{
		cin >> x >> y;
		a[x][y] = a[y][x] = true;
	}
}
