#include <fstream>
#include <vector>

using namespace std;
using VVI = vector<vector<int>>;
using VB  = vector<bool>;

ifstream fin("prieteni.in");
ofstream fout("prieteni.out");

const int N = 1e6 + 1;
int t[N];
int c[N];
int op;
int n, nr_op;
VVI G;
VB v;

void Init();
void Union(int x, int y);
int Find(int x);
void Dfs(int x, int i);

int main()
{
    fin >> n >> nr_op;
    G = VVI(n + 1);
    v = VB(n + 1);
    Init();
    int x, y, p;
    int i = 1;
    while (nr_op--)
    {
        fin >> op;
        if (op == 1)
        {
            fin >> x >> y;
            int r1 = Find(x);
            int r2 = Find(y);
            if (r1 != r2)
            {
                Union(r1, r2);
                G[x].push_back(r2);
                G[y].push_back(r1);
            }
        }

        else
        {
            fin >> p;
            fout << Find(p) << '\n';
            // Dfs(p, i);
            // fout << c[i] << '\n';
            // i++;
            // v.clear();
            // v.resize(n + 1);
        }
    }

    return 0;
}

void Dfs(int x, int i)
{
    v[x] = true;
    ++c[i];
    for (auto const& y : G[x])
        if (!v[y])
            Dfs(y, i);
}

int Find(int x)
{
    if (t[x] == x) return x;
    return t[x] = Find(t[x]);
}

void Union(int x, int y)
{
    if (t[x] > t[y]) t[x] = t[y];
    else t[y] = t[x];
}

void Init()
{
    for (int i = 1; i <= n; ++i)
        t[i] = i;
}