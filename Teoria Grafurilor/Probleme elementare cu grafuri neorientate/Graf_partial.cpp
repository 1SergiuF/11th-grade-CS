#include <fstream>
using namespace std;

ifstream fin("graf_partial.in");
ofstream fout("graf_partial.out");

#define DIM 101
int n;
bool a[DIM][DIM];
int cnt;

void CitesteDate();

int main()
{
    CitesteDate();
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if ((i + j) % 2 == 0 && a[i][j])
            {
                a[i][j] = a[j][i] = false;
                --cnt;
            }

    fout << cnt;

    return 0;
}

void CitesteDate()
{
    fin >> n;
    int x, y;
    while (fin >> x >> y)
    {
        if (a[x][y] == false)
		{
            ++cnt;
			a[x][y] = a[y][x] = true;
		}
    }
}