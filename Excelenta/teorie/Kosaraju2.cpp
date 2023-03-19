#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<int>::reverse_iterator RIT;

ifstream fin("kosaraju.in");
ofstream fout("kosaraju.out");
int n, m;
int contor;
VVI G, GT;
VI S;
VB v;

void ReadGraph();
void Df(int x);
void Dft(int x);
void Kosaraju();

int main()
{
    ReadGraph();
    Kosaraju();
    fout << contor;
    return 0;
}

void Kosaraju()
{
    v = VB(n + 1, false);
    for (int nod = 1; nod <= n; ++nod)
        if (!v[nod])
            Df(nod);

    v = VB(n + 1, false);
    for (RIT it = S.rbegin(); it != S.rend(); ++it)
        if (!v[*it])
        {
            ++contor;
            Dft(*it);
        }
}

void Dft(int x)
{
    v[x] = true;
    for (int const& y : GT[x])
        if (!v[y])
            Dft(y);
}

void Df(int x)
{
    v[x] = true;
    for (int const& y : G[x])
        if (!v[y])
            Df(y);

    S.emplace_back(x);
}

void ReadGraph()
{
    fin >> n >> m;
    G = GT = VVI(n + 1);
    int x, y;
    while (m--)
    {
        fin >> x >> y;
        G[x].emplace_back(y);
        GT[y].emplace_back(x);
    }
}