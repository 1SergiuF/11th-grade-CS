#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("bal.in");
ofstream fout("bal.out");

const int N = 1e5 + 1;

int n, m;
int f[N], b[N];

void CitesteDate();
void Greedy();

int main()
{
    CitesteDate();
    Greedy();

    return 0;
}

void CitesteDate()
{
    fin >> n >> m;

    for (int i = 1; i <= n; ++i)
        fin >> f[i];

    for (int i = 1; i <= m; ++i)
        fin >> b[i];

    sort(f + 1, f + n + 1);
    sort(b + 1, b + m + 1);
}

void Greedy()
{
    int p = 0;
    int i = 1, j = 1;

    while (i <= n && j <= m)
    {
        if (f[i] <= b[j])
        {
            ++p;
            ++i;
            ++j;
        }

        else
            ++j;
    }

    fout << p;
}
