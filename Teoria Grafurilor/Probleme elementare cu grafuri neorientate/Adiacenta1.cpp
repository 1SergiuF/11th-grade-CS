#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("adiacenta1.in");
ofstream fout("adiacenta1.out");

#define Dim 101
bool a[Dim][Dim];
int vmax;

void CitesteGraf();
void AfiseazaMatriceAdiacenta();

int main()
{
    CitesteGraf();
    AfiseazaMatriceAdiacenta();

    return 0;
}

void CitesteGraf()
{
    int x, y;
    while (fin >> x >> y)
    {
        if (!a[x][y])
        {
            a[x][y] = a[y][x] = true;
            vmax = max(vmax, max(x, y));
        }
    }
}

void AfiseazaMatriceAdiacenta()
{
    for (int i = 1; i <= vmax; ++i)
    {
        for (int j = 1; j <= vmax; ++j)
            fout << a[i][j] << ' ';
        fout << '\n';
    }
}