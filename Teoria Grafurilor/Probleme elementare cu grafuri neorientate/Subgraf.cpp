#include <fstream>
using namespace std;

ifstream fin("subgraf.in");
ofstream fout("subgraf.out");

#define Dim 101
bool a[Dim][Dim];
int cnt;
int n;

void CitesteDate();
bool VerifPrim(int x);

int main()
{
    CitesteDate();

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if ((VerifPrim(i) || VerifPrim(j)) && a[i][j])
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
        }
    }
}

bool VerifPrim(int x)
{
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;

    return true;
}