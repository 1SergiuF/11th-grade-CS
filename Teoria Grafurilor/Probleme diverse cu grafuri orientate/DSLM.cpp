#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("dslm.in");
ofstream fout("dslm.out");

const int N = 21;
bool a[N][N];
int L[N];
int aux[101];
int n, p;
int vmax;

void CitesteDate();
void DrumuriMax(int k);
void Update(int k);

int main()
{
    CitesteDate();
    L[1] = p;
    DrumuriMax(2);

    for (int i = 1; i <= vmax; ++i)
        fout << aux[i] << ' ';
    return 0;
}

void DrumuriMax(int k)
{
    for (int i = 1; i <= n; ++i)
    {
        L[k] = i;
        if (a[L[k - 1]][L[k]])
        {
            a[L[k - 1]][L[k]] = false;
            if (k > vmax)
            {
                vmax = k;
                Update(k);
            }

            DrumuriMax(k + 1);
            a[L[k - 1]][L[k]] = true;
        }
    }   
}

void CitesteDate()
{
    fin >> n >> p;
    int x, y;
    while (fin >> x >> y)
        a[x][y] = true;
}

void Update(int k)
{
    for (int i = 1; i <= k; ++i)
        aux[i] = L[i];
}