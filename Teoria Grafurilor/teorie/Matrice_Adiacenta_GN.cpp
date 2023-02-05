/*
  Matrice de adiacenta pentru Grafuri Neorientate
*/

#include <fstream>
using namespace std;

ifstream fin("MAGN.in");
ofstream fout("MAGN.out");

const int N = 101;

bool a[N][N];   // matrice de adiacenta
int n, m;       // nr de noduri/muchii

void CitesteGraf();
void ScrieMatrAdiacenta();

int main()
{
    CitesteGraf();
    ScrieMatrAdiacenta();

    return 0;
}

void CitesteGraf()
{
    fin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        a[x][y] = true;
        a[y][x] = true;
    }
}

void ScrieMatrAdiacenta()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << a[i][j] << ' ';
        fout << '\n';
    }
}