#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("ccmax.in");
ofstream fout("ccmax.out");

#define N 101
bool a[N][N];
int n;
int c[N];
int cc;
int cnt;
int nr_max_varfuri;

using VI = vector<int>;
using VVI = vector<VI>;
using PQ = priority_queue<int>;

VVI G;
PQ pq;

void CitesteGraf();
void Dfs(int x);
void ComponenteConexe();
void DeterminaNrMaxVarfuri();

int main()
{
    CitesteGraf();
    ComponenteConexe();
    DeterminaNrMaxVarfuri();
    return 0;
}

void CitesteGraf()
{
    fin >> n;
    int x, y;
    while (fin >> x >> y)
    {
        if (!a[x][y])
            a[x][y] = a[y][x] = true;
    }
}

void Dfs(int x)
{
    c[x] = cc;
    for (int y = 1; y <= n; ++y)
        if (a[x][y] && !c[y])
            Dfs(y);
}

void ComponenteConexe()
{
    for (int nod = 1; nod <= n; ++nod)
        if (!c[nod])
        {
            cc++;
            Dfs(nod);
        }
}

void DeterminaNrMaxVarfuri()
{
    G = VVI(cc + 1);
    for (int comp = 1; comp <= cc; ++comp)
    {
        for (int x = 1; x <= n; ++x)
            if (c[x] == comp)
                G[comp].push_back(x);

        pq.push(G[comp].size());
    }

    fout << pq.top() << ' ';
    nr_max_varfuri = pq.top();

    while (!pq.empty())
    {
        if (pq.top() == nr_max_varfuri)
            ++cnt;
        pq.pop();
    }

    fout << cnt;
}