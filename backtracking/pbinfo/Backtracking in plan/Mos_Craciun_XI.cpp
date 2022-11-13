#include <iostream>
using namespace std;

const int N = 20,
          di[] = {-1, 1, 1, -1},
          dj[] = {1, 1, -1, -1};

bool L[N][N];
int x[N][N];
int n;
int nrsol, lmax;

void CitesteLabirint();
bool Ok(int i, int j);
void Labir(int i, int j, int k);

int main()
{
    CitesteLabirint();
    Labir(1, 1, 1);

    if (!nrsol)
        cout << "Dorel :((";
    else
        cout << nrsol << '\n' << lmax;
    return 0;
}

void CitesteLabirint()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> L[i][j];
}

bool Ok(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > n) return false;
    if (L[i][j]) return false;
    if (x[i][j]) return false;

    return true;
}

#define iv (i + di[d])
#define jv (j + dj[d])

void Labir(int i, int j, int k)
{
    if (!Ok(i, j)) return;
    x[i][j] = k;

    if (i == n && j == n)
    {
        if (lmax < k)
            lmax = k;
        ++nrsol;
        x[i][j] = 0;
        return;
    }

    for (int d = 0; d < 4; ++d)
        Labir(iv, jv, k + 1);

    x[i][j] = 0;
}