/*
  Breadth First Search
  PArcurgere pe Latime/Largime
*/

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

    while (p <= u)  // cat timp coada nu e vida
    {
        x = Q[p];   // aflam primul nod din coada
        ++p;        // "stergem" primul nod din coada

        for (int y = 1; y <= n; ++y)
        {
            if (a[x][y] && !v[y])   // daca am gasit un nod y, nevizitat, al lui x
            {
                v[y] = true;
                fout << y << ' ';
                Q[++u] = y;
            }
        }
    }
}