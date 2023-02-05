/*
  Gradele nodurilor Grafuri Orientate
*/

#include <fstream>
using namespace std;

ifstream fin("graf2.in");
ofstream fout("graf2.out");

const int N = 101;

bool a[N][N];
int ge[N];  // ge[x] = gradul exterior (extern) al nodului x
int gi[N];  // gi[x] = gradul interior (intern) al nodului x
int n;      // nr de noduri

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
            a[x][y] = true;
            ge[x]++;
            gi[y]++;
        }
    }
}

void ScrieGrade()
{
    for (int i = 1; i <= n; ++i)
        fout << ge[i] << ' ';
    
    fout << '\n';

    for (int i = 1; i <= n; ++i)
        fout << gi[i] << ' ';
}