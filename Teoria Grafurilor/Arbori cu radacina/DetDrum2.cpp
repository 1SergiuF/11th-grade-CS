#include <fstream>
#include <vector>
using namespace std;
using VVI = vector<vector<int>>;

ifstream fin("detdrum2.in");
ofstream fout("detdrum2.out");

const int N = 101;
int t[N], T[N];
vector<bool> v;
VVI G;
int n, p, q;

void Dfs(int nod);
int main()
{
    fin >> n >> p >> q;
    G = VVI(n + 1);
    v = vector<bool>(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        fin >> t[i];
        if (t[i])
        {
            G[t[i]].push_back(i);
            G[i].push_back(t[i]);
        }
    }

    Dfs(q);

    while (T[p])
    {
        fout << p << ' ';
        p = T[p];
    }

    fout << p;
    return 0;
}

void Dfs(int nod)
{   
    v[nod] = true;
    for (auto y : G[nod])
        if (!v[y])
        {
            Dfs(y);
            T[y] = nod;
        }
}