#include <fstream>
using namespace std;

ifstream fin("lant1.in");
ofstream fout("lant1.out");

const int N = 101;
bool a[N][N];
bool v[N];
int L[N];
int n, p, q, r;

void CitesteGraf();
void Lant(int x, int k);
void ScrieLant(int k);

int main()
{
    CitesteGraf();
    Lant(p, 1);
    return 0;
}

void Lant(int x, int k)
{
    v[x] = true;
    L[k] = x;
    if (x == q)
    {
        if (v[r])
        {
            ScrieLant(k);
            exit(0);
        }

        v[x] = false;
        return;
    }

    for (int y = 1; y <= n; ++y)
        if (a[x][y] && !v[y])
            Lant(y, k + 1);

    v[x] = false;
}

void ScrieLant(int k)
{
    fout << k << '\n';
    for (int i = 1; i <= k; ++i)
        fout << L[i] << ' ';
}

void CitesteGraf()
{
    fin >> n >> p >> q >> r;
    int x, y;
    while (fin >> x >> y)
    {
        if (!a[x][y])
            a[x][y] = a[y][x] = true;
    }
}