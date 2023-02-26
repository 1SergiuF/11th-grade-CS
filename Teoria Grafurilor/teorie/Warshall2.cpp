/*
    Alg Warshall
    - determina pentru oricare doua varfuri ale grafrului
      daca exista lant/drum intre acestea
    - det, "Inchiderea tranzitiva" (Trasitive closure)

    - transforma matricea de adiacenta in matricea lanturilor/drumurilor

*/
#include <fstream>
using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

const int N = 201;
bool a[N][N];  // matricea de adiacenta => se va transforma
              // in matricea lanturilor/drumurilor
int n, m;

void CitesteGraf();
void Warshall();
void ScrieMatr();

int main()
{
    CitesteGraf();
    ScrieMatr();  // matricea de adiacenta
    Warshall();
    ScrieMatr();  // matricea lanturilor/drumurilor
}

void Warshall() // O(n^3)
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i != j && !a[i][j])
                    a[i][j] = a[i][k] && a[k][j];
}

void ScrieMatr()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << a[i][j] << ' ';
        fout << '\n';
    }

    fout << "\n\n";
}

void CitesteGraf()
{
    fin >> n >> m;
    int x, y;
    while (m--)
    {
        fin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
}