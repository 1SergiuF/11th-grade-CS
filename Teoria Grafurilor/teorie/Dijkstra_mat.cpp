#include <fstream>
using namespace std;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

const int N = 1001, Inf = 0x3f3f3f3f;
int c[N][N];
bool s[N];
int d[N];
int n, m;

void CitesteGraf();
void Dijkstra(int x, int d[]);
void ScrieDistanteMinime();

int main()
{
    CitesteGraf();
    Dijkstra(1, d);
    ScrieDistanteMinime();
    return 0;
}

void Dijkstra(int x, int d[])
{
    d[x] = 0;
    s[x] = true;

    for (int j = 1; j <= n; ++j)
        d[j] = c[x][j];

    for (int pas = 1; pas <= n - 1; ++pas)
    {
        int dmin = Inf;
        for (int i = 1; i <= n; ++i)
            if (!s[i] && d[i] < dmin)
            {
                dmin = d[i];
                x = i;
            }

        s[x] = true;
        for (int y = 1; y <= n; ++y)
            if (d[y] > d[x] + c[x][y])
                d[y] = d[x] + c[x][y];
    }
}

void CitesteGraf()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                c[i][j] = Inf;
    
    int x, y, w;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y >> w;
        c[x][y] = w;
        c[y][x] = w;
    }
}

void ScrieDistanteMinime()
{
    for (int i = 1; i <= n; ++i)
        fout << (d[i] != Inf ? d[i] : -1) << ' ';
}