/*
  Breadth First Search
  Parcurgere pe Latime/Largime
*/

#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("BFS.in");
ofstream fout("BFS.out");

using VI = vector<int>;
using VB = vector<bool>;
using VVI = vector<VI>;

VVI G;
VB v;
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

    G = VVI(n + 1);
    v = VB(n + 1);

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
    fout << x << ' ';
    Q.push(x);

    while (!Q.empty())
    {
        x = Q.front();
        Q.pop();    // stergem primul nod din coada

        for (const int& y : G[x])
        {
            if (v[y]) continue;
            v[y] = true;
            fout << y << ' ';
            Q.push(y);
        }
    }
}