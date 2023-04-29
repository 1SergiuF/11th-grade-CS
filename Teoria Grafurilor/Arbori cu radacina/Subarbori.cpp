#include <fstream>
using namespace std;

ifstream fin("subarbori.in");
ofstream fout("subarbori.out");

const int N = 101;
int t[N];
int frecv[N];
int n;
int root;
int cnt = 1;

int Dfs(int nod);
int main()
{
    fin >> n;
    int nr_perechi = 0;
    for (int i = 1; i <= n; ++i)
    {
        fin >> t[i];
        if (t[i] == 0)
            root = i;
    }

    for (int i = 1; i < n; ++i)
    {
        int s1 = Dfs(i);
        cnt = 1;
        for (int j = i + 1; j <= n; ++j)
        {
            int s2 = Dfs(j);
            if (s1 == s2 && (s1 != 1 || s2 != 1))
                ++nr_perechi;

            cnt = 1;
        }
    }

    fout << nr_perechi;

    return 0;
}

int Dfs(int nod)
{
    for (int f = 1; f <= n; ++f)
        if (t[f] == nod)
            cnt = 1 + Dfs(f);

    return cnt;
}