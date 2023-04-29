#include <fstream>
using namespace std;

ifstream fin("subarbore2.in");
ofstream fout("subarbore2.out");

const int N = 101;
int t[N];
int val[N];
int sum;
int n, k;

void Dfs(int nod);
int main()
{
    fin >> n >> k;
    for (int i = 1; i <= n; ++i)
        fin >> t[i];

    for (int i = 1; i <= n; ++i)
        fin >> val[i];

    Dfs(k);
    fout << sum;
    return 0;  
}

void Dfs(int nod)
{
    sum += val[nod];
    for (int f = 1; f <= n; ++f)
        if (t[f] == nod)
            Dfs(f);
}