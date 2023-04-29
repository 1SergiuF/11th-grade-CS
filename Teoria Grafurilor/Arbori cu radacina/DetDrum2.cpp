#include <fstream>
using namespace std;

ifstream fin("detdrum2.in");
ofstream fout("detdrum2.out");

const int N = 101;
int t[N];
int n, p, q;

void Dfs(int nod);
int main()
{
    fin >> n >> p >> q;

    for (int i = 1; i <= n; ++i)
        fin >> t[i];

    Dfs(p);

    return 0;
}

void Dfs(int nod)
{
    fout << nod << ' ';
    for (int f = 1; f <= n; ++f)
        if (t[f] == nod)
            Dfs(f);
}