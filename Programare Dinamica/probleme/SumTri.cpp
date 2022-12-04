#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("sumtri.in");
ofstream fout("sumtri.out");

const int Dim = 101;

int a[Dim][Dim];
int s[Dim][Dim];
int n;
int smax;

void ReadTriangle();
void DP();

int main()
{
	ReadTriangle();
	DP();

	fout << smax;

	return 0;
}

void ReadTriangle()
{
	fin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			fin >> a[i][j];
}

void DP()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			s[i][j] = max(s[i - 1][j - 1], s[i - 1][j])
					  + a[i][j];

	for (int i = 1; i <= n; ++i)
		smax = max(smax, s[n][i]);
}