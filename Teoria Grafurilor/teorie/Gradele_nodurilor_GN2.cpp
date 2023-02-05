/*
  Gradele nodurilor
*/

#include <fstream>
using namespace std;

ifstream fin("graf1.in");
ofstream fout("graf1.out");

const int N = 101;

bool a[N][N];
int g[N];   // g[x] = gradul nodului x
int n;  // nr de noduri

void CitesteGraf();
void ScrieGrade();

int main()
{
    CitesteGraf();
    ScrieGrade();

    return 0;
}

void CitesteGraf()
{
    fin >> n;
    int x, y;
    while (fin >> x >> y)
    {
        if (!a[x][y])
        {
            a[x][y] = a[y][x] = true;
            g[x]++;
            g[y]++;
        }
    }
}

void ScrieGrade()
{
    for (int i = 1; i <= n; ++i)
        fout << g[i] << ' ';
}