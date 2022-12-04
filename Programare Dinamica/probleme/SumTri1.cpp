#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("sumtri1.in");
ofstream fout("sumtri1.out");

const int Dim = 101;

int a[Dim][Dim], c[Dim][Dim];
bool b[Dim][Dim];
int rez[Dim];
int n;
int smin = 1e8 + 1;
int f;

void ReadTriangle();
void DP();

int main()
{
	ReadTriangle();

	for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            a[i][j] = 1e8 + 1;

    for(int i = 1; i <= n; ++i)
        a[i][0] = 1e8 + 1;

	DP();

	return 0;
}

void ReadTriangle()
{
	fin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			fin >> a[i][j], c[i][j] = a[i][j];
}

void DP()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			a[i][j] += min(a[i - 1][j], a[i - 1][j - 1]);
			if (a[i - 1][j] > a[i - 1][j - 1]) b[i][j] = false;
			else b[i][j] = true;

		}
	}

    for(int i = 1 ; i <= n ; i++)
        if(a[n][i] < smin) smin = a[n][i], f = i;

    fout << smin << '\n';

    int i = n, j = f, k = 0;

    while (i >= 1)
    {
    	rez[++k] = c[i][j];
    	if(!b[i][j])
    		j--;
    	i--;
    }

    for (int i = n; i >= 1; --i)
    	fout << rez[i] << ' ';
}