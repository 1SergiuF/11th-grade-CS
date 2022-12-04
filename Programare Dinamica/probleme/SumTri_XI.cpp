#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("sumtri_xi.in");
ofstream fout("sumtri_xi.out");

const int N = 101;

int n;
int a[N][N];
int s[N][N];

void CitesteDate();
void Dinamica();

int main()
{
    CitesteDate();
    Dinamica();

    return 0;
}

void CitesteDate()
{
    fin >> n;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            fin >> a[i][j];
}

void Dinamica()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			s[i][j] = max(s[i][j - 1], s[i - 1][j - 1])
					  + a[i][j];

    fout << s[n][n];
}