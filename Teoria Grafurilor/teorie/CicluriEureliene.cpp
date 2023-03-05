/*
    Generarea ciclurilor euleriene
*/
#include <fstream>
using namespace std;

ifstream fin("cicluri_euleriene.in");
ofstream fout("cicluri_euleriene.out");

const int N = 20;
bool a[N][N];
int gr[N];   // sirul graredelor nodurilor
bool v[N][N];// v[i][j] = true daca muchia i-j a fost parcursa (a fost plasata in x[])
int x[N];    // retine lantul simplu curent
bool conex[N];
int nr_sol;
int n, m;

void CitesteGraf();
void CicluEuler(int k);
bool Ok(int k);
void ScrieCiclu();
bool EsteEulerin();
bool EsteConex();
void Dfs(int x);

int main()
{
    CitesteGraf();

    if (EsteEulerin())
    {
        x[1] = 1;
        CicluEuler(2);
    }
    else
        fout << "Nu este eulerian";

}

void CicluEuler(int k)
{
    if (k == m + 2)
    {
        if (x[m + 1] == 1)
            ScrieCiclu();
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        x[k] = i;
        if (Ok(k))
        {
            v[x[k - 1]][i] = true; // marcam muchia
            CicluEuler(k + 1);
            v[x[k - 1]][i] = false; // demarcam muchia
        }
    }
}

bool Ok(int k)
{
     if (!a[x[k - 1]][x[k]]) // nu exista muchie cu nodul anterior al lantului
        return false;
    if (v[x[k - 1]][x[k]] ||
        v[x[k]][x[k - 1]])
        return false;

    return true;
}

bool EsteEulerin()
{
    for (int x = 1; x <= n; ++x)
        if (gr[x] % 2 == 1)
            return false;

    if (!EsteConex())  // O(m)
        return false;
    return true;
}

void ScrieCiclu()
{
    nr_sol++;
    for (int i = 1; i <= m + 1; ++i)
        fout << x[i] << ' ';
    fout << '\n';
}

bool EsteConex()
{
    for (int i = 1; i <= n; ++i)
        if (!conex[i])
            return false;

    return true;
}

void Dfs(int x)
{
    conex[x] = true;
    for (int y = 1; y <= n; ++y)
        if (a[x][y] && !conex[y])
            Dfs(y);
}

void CitesteGraf()
{
    fin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;

        if (a[x][y] == false)
        {
            gr[x]++; gr[y]++;
            a[x][y] = a[y][x] = true;
        }
    }
}