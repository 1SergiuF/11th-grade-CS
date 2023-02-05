/*
  Depth First Search
*/

#include <fstream>
#include <vector>
#include <set>
using namespace std;

ifstream fin("dfs2.in");
ofstream fout("dfs2.out");

// Type alias-uri
using VI = vector<int>;
using SI = set<int>;
using VB = vector<bool>;
using VSI = vector<SI>;

int n, m;
VSI G;  // G = vector vid
VB v;

void CitesteGraf();
void Dfs(int x);

int main()
{
    CitesteGraf();
    Dfs(1);
    return 0;
}

void CitesteGraf()
{
    fin >> n >> m;
    G = VSI(n + 1);   // acum avem G[0], G[1], ..., G[n] - vectori vizi
    v = VB(n + 1);

    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        G[x].insert(y);  // O(log2(size))
        G[y].insert(x);
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