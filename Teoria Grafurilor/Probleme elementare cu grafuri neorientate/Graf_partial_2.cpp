#include <fstream>
using namespace std;

ifstream fin("graf_partial_2.in");
ofstream fout("graf_partial_2.out");

#define Dim 101

bool a[Dim][Dim];
int g[Dim];
int n;
int vmax;
int cnt;

void CitesteGraf();
void DeterminaGradMax();

int main()
{
	CitesteGraf();
	DeterminaGradMax();

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i][j] && (g[i] == vmax || g[j] == vmax))
			{
				++cnt;
				a[i][j] = a[j][i] = false;
			}

	fout << cnt << '\n';

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			fout << a[i][j] << ' ';
		fout << '\n';
	}
	
	return 0;
}

void CitesteGraf()
{
	fin >> n;
	int x, y;
	while (fin >> x >> y)
	{
		if (!a[x][y])
		{
			a[x][y] = a[y][x] = true;
			g[x]++;
			g[y]++;
		}
	}
}

void DeterminaGradMax()
{
	vmax = -Dim;
	for (int i = 1; i <= n; ++i)
		if (vmax < g[i])
			vmax = g[i];
}