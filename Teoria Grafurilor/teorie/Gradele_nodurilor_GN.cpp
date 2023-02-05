/*
  Gradele nodurilor
*/

#include <fstream>
using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

const int N = 101;

int g[N];   // g[x] = gradul nodului x
int n, m;   // nr de noduri/muchii

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
    fin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        g[x]++;
        g[y]++;
    }
}

void ScrieGrade()
{
    for (int i = 1; i <= n; ++i)
        fout << g[i] << ' ';
}