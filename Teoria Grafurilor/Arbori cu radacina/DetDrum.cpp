#include <fstream>
using namespace std;

ifstream fin("detdrum.in");
ofstream fout("detdrum.out");

const int N = 101;
int t[N];
int n, k;

void Dfs(int nod);
int main()
{
    fin >> n >> k;

    for (int i = 1; i <= n; ++i)
        fin >> t[i];

    Dfs(k);

    return 0;
}

void Dfs(int nod)
{
    fout << nod << ' ';
    for (int f = 1; f <= n; ++f)
        if (t[nod] == f)
            Dfs(f);
}