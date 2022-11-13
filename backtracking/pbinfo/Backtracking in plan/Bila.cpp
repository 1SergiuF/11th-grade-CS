#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("bila.in");
ofstream fout("bila.out");

const int N = 50;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int n, m;
int x[N][N], L[N][N];
int istart, jstart;
int lmax;

void CitesteDate();
bool Ok(int i, int j);
void Labirint(int i, int j, int k);

int main()
{
    CitesteDate();
    Labirint(istart, jstart, 0);

    fout << lmax;

    return 0;
}

void CitesteDate()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> L[i][j];
    
    fin >> istart >> jstart;
    x[istart][jstart] = 1;
}

bool Ok(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m)
        return false;

    return true;
}

#define iv (i + di[d])
#define jv (j + dj[d])

void Labirint(int i, int j, int k)
{
    if (!Ok(i, j))
    {
        lmax = max(lmax, k);
        return;
    }

    for (int d = 0; d < 4; ++d)
    {
        if (!x[iv][jv] && L[iv][jv] < L[i][j])
        {
            x[i][j] = k;
            Labirint(iv, jv, k + 1);
        }
    }
}
