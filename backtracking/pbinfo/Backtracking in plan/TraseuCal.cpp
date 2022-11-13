#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

ifstream fin("traseucal.in");
ofstream fout("traseucal.out");

const int N = 20;
const int di[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dj[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int n, m;
int x[N][N];

void CitesteLabirint();
bool Ok(int i, int j);
void Labirint(int i, int j, int k);
void ScrieSol();

int main()
{
	CitesteLabirint();
	Labirint(1, 1, 1);
	ScrieSol();

	return 0;
}

void CitesteLabirint()
{
	fin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			fin >> x[i][j];
			if (x[i][j] == 1)
				x[i][j] = -1;
		}
}

bool Ok(int i, int j)
{
	if (i < 1 || i > n || j < 1 || j > m)
		return false;

	if (x[i][j] == -1)
		return false;

	if (x[i][j])
		return false;

	return true;
}

#define iv (i + di[d])
#define jv (j + dj[d])

void Labirint(int i, int j, int k)
{
	if (!Ok(i, j)) return;
	x[i][j] = k;

	if (i == n && j == m)
	{
		ScrieSol();
		exit(0);
	}

	for (int d = 0; d < 8; ++d)
		Labirint(iv, jv, k + 1);

	x[i][j] = 0;
}

void ScrieSol()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (x[i][j] == -1)
				fout << 0 << ' ';
			else
				fout << x[i][j] << ' ';
		}

		fout << '\n';
	}
}