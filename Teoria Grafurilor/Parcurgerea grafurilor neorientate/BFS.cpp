#include <fstream>
using namespace std;

ifstream fin("BFS.in");
ofstream fout("BFS.out");

#define Dim 101
bool a[Dim][Dim];
bool v[Dim];
int n, m, X;

void CitesteGraf();
void Bfs(int x);

int main()
{
    CitesteGraf();
    Bfs(X);

    return 0;
}

void CitesteGraf()
{
    fin >> n >> m >> X;

    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        a[x][y] = a[y][x] = true;
    }
}

void Bfs(int x)
{
    int Q[Dim];
    int p = 0, u = -1;

    v[x] = true;
    fout << x << ' ';
    Q[++u] = x;

    while (p <= u)
    {
        x = Q[p];
        ++p;

        for (int y = 1; y <= n; ++y)
        {
            if (a[x][y] && !v[y])
            {
                v[y] = true;
                fout << y << ' ';
                Q[++u] = y;
            }
        }
    }
}