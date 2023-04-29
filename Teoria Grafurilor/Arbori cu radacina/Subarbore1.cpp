#include <fstream>
#include <set>
#include <vector>
using namespace std;

ifstream fin("subarbore1.in");
ofstream fout("subarbore1.out");

const int N = 101;
int t[N];
int n, k;
vector<bool> frunze;
set<int> s;

void Dfs(int nod);
int main()
{
    fin >> n >> k;
    frunze = vector<bool>(n + 1, true);
    for (int i = 1; i <= n; ++i)
    {
        fin >> t[i];
        frunze[t[i]] = false;
    }

    Dfs(k);
    for (int y : s)
        fout << y << ' ';
    return 0;
}

void Dfs(int nod)
{
    if (frunze[nod]) s.insert(nod);
    for (int f = 1; f <= n; ++f)
        if (t[f] == nod)
            Dfs(f);
}