/*
  Parcurgerea in Adancime
  Depth First Search

*/

#include <fstream>
using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

#define Dim 101
bool a[Dim][Dim];
bool v[Dim];    // retine starea de vizitare a nodurilor
int n, m, X;

void CitesteDate();
void Dfs(int x);

int main()
{
    CitesteDate();
    Dfs(X);
    return 0;
}

void CitesteDate()
{
    fin >> n >> m >> X;
    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        a[x][y] = a[y][x] = true;
    }
}

void Dfs(int x)
{
    v[x] = true;
    fout << x << ' ';
    for (int y = 1; y <= n; ++y)
        if (a[x][y] && !v[y])   // daca y este vecin nevizitat al lui x
            Dfs(y);
}