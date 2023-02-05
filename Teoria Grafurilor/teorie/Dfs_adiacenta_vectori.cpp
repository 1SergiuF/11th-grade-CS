/*
  Depth First Search
*/

#include <fstream>
#include <vector>
using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

// Type alias-uri
using VI = vector<int>;
using VB = vector<bool>;
using VVI = vector<VI>;

int n, m, X;
VVI G;  // G = vector vid
VB v;

void CitesteGraf();
void Dfs(int x);

int main()
{
    CitesteGraf();
    Dfs(X);
    return 0;
}

void CitesteGraf()
{
    fin >> n >> m >> X;
    G = VVI(n + 1);   // acum avem G[0], G[1], ..., G[n] - vectori vizi
    v = VB(n + 1);

    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        G[x].push_back(y);  // O(log2(size))
        G[y].push_back(x);
    }
}

void Dfs(int x)
{
    v[x] = true;
    fout << x << ' ';
    for (int y : G[x])
        if (!v[y])
            Dfs(y);
}