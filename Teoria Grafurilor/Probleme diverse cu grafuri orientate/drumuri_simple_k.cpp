#include <iostream>
using namespace std;

const int N = 21;
bool a[N][N];
bool v[N][N];
int L[N];
int n, m, l;
bool ok;

void CitesteGraf();
void Drumuri(int x, int k);
void ScrieDrum();

int main()
{
	CitesteGraf();
	for (int i = 1; i <= n; ++i)
		Drumuri(i, 1);
	
	if (!ok) cout << "Nu exista";
	return 0;
}

void Drumuri(int x, int k)
{
	L[k] = x;
	
	if (k == l + 1)
	{
		ScrieDrum();
		return;
	}
	
	for (int y = 1; y <= n; ++y)
		if (a[x][y] && !v[x][y])
		{
			v[x][y] = true;
			Drumuri(y, k + 1);
			v[x][y] = false;
		}
}

void ScrieDrum()
{
	ok = true;
	for (int i = 1; i <= l + 1; ++i)
		cout << L[i] << ' ';
	cout << '\n';
}

void CitesteGraf()
{
	cin >> n >> m >> l;
	for (int i = 1, x, y; i <= m; ++i)
	{
		cin >> x >> y;
		a[x][y] = true;
	}
}
