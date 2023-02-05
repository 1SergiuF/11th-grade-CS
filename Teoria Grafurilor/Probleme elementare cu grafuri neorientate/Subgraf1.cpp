#include <fstream>
#include <climits>
using namespace std;

ifstream fin("subgraf1.in");
ofstream fout("subgraf1.out");

#define Dim 101

int n;
bool a[Dim][Dim];
int g[Dim];
int cnt;

void CitesteDate();
int DeterminaGradMinim(int vmin);

int main()
{
    CitesteDate();

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if ((g[i] == DeterminaGradMinim(INT_MAX) ||
                g[j] == DeterminaGradMinim(INT_MAX)) &&
                a[i][j])
            {
                --cnt;
                a[i][j] = a[j][i] = false;
            }

    fout << cnt;
    
    return 0;
}

void CitesteDate()
{
    fin >> n;
    int x, y;

    while (fin >> x >> y)
    {
        if (!a[x][y])
        {
            ++cnt;
            a[x][y] = a[y][x] = true;
            g[x]++;
            g[y]++;
        }
    }
}

int DeterminaGradMinim(int vmin)
{
    for (int i = 1; i <= n; ++i)
        if (vmin > g[i])
            vmin = g[i];

    return vmin;
}