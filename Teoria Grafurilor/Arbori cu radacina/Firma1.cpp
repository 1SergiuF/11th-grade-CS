#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("firma1.in");
ofstream fout("firma1.out");

const int N = 101;
int castig[N];
int t[N];
int sal[N];
int n;
int root;
int cnt;

void Dfs(int x);

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> t[i];
        if (t[i] == 0)
            root = i;
    }

    for (int i = 1; i <= n; ++i)
        fin >> sal[i];

    Dfs(root);
    fout << castig[root];
    return 0;
}

void Dfs(int x)
{
    for (int f = 1; f <= n; ++f)
        if (t[f] == x)
            Dfs(f);

    cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (x == t[i])
        {
            castig[x] += castig[i];
            ++cnt;
        }
    }

    if (cnt)
    {
        if (ceil((double)castig[x] / cnt) == floor((double)castig[x] / cnt))
            castig[x] /= cnt;

        else
        {   castig[x] /= cnt;
            castig[x] += 1;       
        }
    }

    castig[x] += sal[x];
}