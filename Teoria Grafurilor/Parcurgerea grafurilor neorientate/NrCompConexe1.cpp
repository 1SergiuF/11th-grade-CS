#include <fstream>
#include <vector>
using namespace std;

ifstream fin("nrcompconexe1.in");
ofstream fout("nrcompconexe1.out");

typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;

VVI G, cc;
VI c;
VB v;
int n, m;

void CitesteGraf();
void ComponenteConexe();
void Dfs(int x);

int main()
{
    CitesteGraf();
    ComponenteConexe();

    fout << cc.size();
    
    return 0;
}

void ComponenteConexe()
{
    for (int nod = 1; nod <= n; ++nod)
        if (!v[nod])
        {
            c.clear();
            Dfs(nod);
            cc.push_back(c);
        }
}

void Dfs(int x)
{
    v[x] = true;
    c.push_back(x);
    for (auto const& y : G[x])
        if (!v[y])
            Dfs(y);
}

void CitesteGraf()
{
    fin >> n >> m;
    G = VVI(n + 1);
    v = VB(n + 1);

    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}