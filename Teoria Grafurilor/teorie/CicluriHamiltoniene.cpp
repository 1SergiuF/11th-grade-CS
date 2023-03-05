/*
    Generarea ciclurilor hamiltoniene
*/
#include <fstream>
using namespace std;

ifstream fin("cicluri_hamiloniene.in");
ofstream fout("cicluri_hamiloniene.out");

const int N = 20;
bool a[N][N];
int n, m;
bool v[N];
int x[N];    // retine lantul elementar curent
int nr_sol;

void CitesteGraf();
void CicluHamilt(int k);
bool Ok(int k);
void ScrieCiclu();


int main()
{
    CitesteGraf();
    x[1] = 1;
    v[1] = true;
    CicluHamilt(2);
}

void CicluHamilt(int k)
{
    if (k > n)
    {
        if (a[x[n]][x[1]])
            ScrieCiclu();
        return;
    }

    for (int i = 2; i <= n; ++i)
    {
        x[k] = i;
        if (Ok(k))
        {
            v[i] = true;
            CicluHamilt(k + 1);
            v[i] = false;
        }
    }
}

bool Ok(int k)
{
    if (v[x[k]])  // daca nodul a mai fost vizitat (a mai fost plasat in x[])
        return false;

    if (!a[x[k - 1]][x[k]]) // nu exista muchie cu nodul anterior al lantului
        return false;
    return true;
}

void ScrieCiclu()
{
    nr_sol++;
    for (int i = 1; i <= n; ++i)
        fout << x[i] << ' ';
    fout << x[1] << '\n';
}

void CitesteGraf()
{
    fin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        a[x][y] = a[y][x] = true;
    }
}