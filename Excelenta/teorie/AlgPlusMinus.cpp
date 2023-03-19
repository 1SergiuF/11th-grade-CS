/* 
 * Det Componentelor tare-conexe pt un G.O.
 * Algoritmul Plus-Minus 
 */ 

#include <iostream>
using namespace std;

const int N = 101;
bool a[N][N];
int s[N];   // marcheaza nodurile vizitate pe graful G
int p[N];   // marcheaza nodurile vizitate pe graful Gt (transpus)

int n, m;
int ctc;    // nr de comp tare-conexe

void CitesteGraf();
void Df(int x);
void Dft(int x);    // pe graful transpus
void CompTareConexe();

int main()
{
    CitesteGraf();
    CompTareConexe();

    return 0;
}

void CompTareConexe()   // O(m + n * n)
{
    for (int nod = 1; nod <= n; ++nod)
        if (!s[nod])
        {
            ++ctc;
            Df(nod);
            Dft(nod);

            for (int i = 1; i <= n; ++i)
                if (s[i] == p[i] && s[i] == ctc)
                    cout << i << ' ';
                else
                    if (!s[i] || !p[i])
                        s[i] = p[i] = 0;

            cout << '\n';
        }
}

void Dft(int x) // O(m)
{
    p[x] = ctc;
    for (int y = 1; y <= n; ++y)
    {
        if (p[y] || !a[y][x]) continue;
        Dft(y);
    }
}

void Df(int x)  // O(m)
{
    s[x] = ctc;
    for (int y = 1; y <= n; ++y)
    {
        if (s[y] || !a[x][y]) continue;
        Df(y);
    }
}

void CitesteGraf()
{
    cin >> n >> m;
    int x, y;
    while (m--)
    {
        cin >> x >> y;
        a[x][y] = true;
    }
}