/*
  Breadth First Search
  Parcurgere pe Latime/Largime
  Complexitate: O(m + n) aprox O(m)
*/

#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("bfs_stl.in");
ofstream fout("bfs_stl.out");

using VI = vector<int>;
using VB = vector<bool>;
using VVI = vector<VI>;

VVI G;
VB v;
VI d;   // d[x] = distanta minima de la nodul sursa la nodul x
VI t;   // sirul de tati (retine arborele BSF)
int n, m;

void CitesteGraf();
void Bfs(int x);
void Lant(int x);

int main()
{
    CitesteGraf();
    // distanta minima de la 9 la 6
    Bfs(9);
    fout << d[6] << '\n';
    Lant(6);
    return 0;
}

void CitesteGraf()
{
    fin >> n >> m;
    G = VVI(n + 1);
    v = VB(n + 1);
    d = t = VI(n + 1);

    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

void Bfs(int x)
{
    queue<int> Q;   // coada vida
    v[x] = true;
    d[x] = 0;   // pt ca x este radacina arborelui BFS
    t[x] = 0;
    Q.push(x);

    while (!Q.empty())
    {
        x = Q.front();
        Q.pop();    // stergem primul nod din coada

        for (int y : G[x])
        {
            if (v[y]) continue;
            v[y] = true;
            d[y] = d[x] + 1;
            t[y] = x;
            Q.push(y);
        }
    }
}

void Lant(int x)
{
    if (x == 0) return;
    Lant(t[x]);
    fout << x << ' ';
}