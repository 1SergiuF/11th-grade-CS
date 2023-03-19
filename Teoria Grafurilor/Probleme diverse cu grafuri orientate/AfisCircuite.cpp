#include <iostream>
using namespace std;

const int N = 101;
bool a[N][N];
int n, m;

void CitesteGraf();
int main()
{
	CitesteGraf();
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				if (a[i][j] && a[k][i] && a[j][k])
					cout << i << ' ' << j << ' ' << k << '\n';
					
	return 0;
}

void CitesteGraf()
{
	cin >> n >> m;
	int x, y;
	while (m--)
	{
		cin >> x >> y;
		a[x][y] = true;
	}
}
