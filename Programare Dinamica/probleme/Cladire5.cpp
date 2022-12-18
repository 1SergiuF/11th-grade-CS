#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("cladire5.in");
ofstream fout("cladire5.out");

const int Dim = 201;
const int Inf = 1e8;

int n, m, bani;
int a[Dim][Dim];
int dp[Dim][Dim];

void CitesteCladire();
void Dinamica();

int main()
{
	CitesteCladire();
	Dinamica();

	return 0;
}

void CitesteCladire()
{
	fin >> n >> m >> bani;

	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= m + 1; ++j)
			dp[i][j] = Inf;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			fin >> a[i][j];
}

void Dinamica()
{
	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= 1; --j)
		{
			int vmin = min(dp[i - 1][j], dp[i][j + 1]);
			if (vmin != Inf)
				dp[i][j] = vmin + a[i][j];
			else
				dp[i][j] = a[i][j];
		}

	// for (int i = 1; i <= n; ++i)
	// {
	// 	for (int j = 1; j <= m; ++j)
	// 		fout << dp[i][j] << ' ';
	// 	fout << '\n';
	// }
	fout << bani - dp[n][1];
}
