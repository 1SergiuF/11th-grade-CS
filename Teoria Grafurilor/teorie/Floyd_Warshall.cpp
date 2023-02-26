/*
    Alg Floyd-Warshall  (Roy-Floyd)
    - determina pentru oricare doua varfuri ale grafrului
      costul minim al unui lant/drum care le uneste

    - transforma matricea ponderilor
      in matricea costurilor minime ale lanturilor/drumurilor

*/
#include <fstream>
#include <iomanip>
using namespace std;

ifstream fin("graf2.in");
ofstream fout("graf2.out");

const int N = 201, Inf = 1 << 29;
int c[N][N];  // matricea ponderilor (costul muchiilor)
              // se va transforma in matricea costurilor minime
              // ale lanturilor/drumurilor
int n, m;

void CitesteGraf();
void Floyd_Warshall();
void ScrieMatr();

int main()
{
    CitesteGraf();
    ScrieMatr();  // matricea de adiacenta
    Floyd_Warshall();
    ScrieMatr();  // matricea lanturilor/drumurilor
}

void Floyd_Warshall() // O(n^3)
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i != j && c[i][j] > c[i][k] + c[k][j])
                    c[i][j] = c[i][k] + c[k][j];
}

void ScrieMatr()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            if (c[i][j] == Inf)
                fout << "  oo";
            else
                fout << setw(4)<< c[i][j];
        fout << '\n';
    }

    fout << "\n\n";
}

void CitesteGraf()
{
    fin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                c[i][j] = Inf;

    int x, y, w;   // w = ponderea(costul) muchiei x-y
    while (m--)
    {
        fin >> x >> y >> w;
        c[x][y] = w;
        c[y][x] = w;
    }
}