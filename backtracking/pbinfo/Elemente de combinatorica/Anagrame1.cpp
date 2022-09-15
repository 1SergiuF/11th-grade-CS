#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream fin("anagrame1.in");
ofstream fout("anagrame1.out");

char a[15];
int x[15];
bool pus[15];
int n;

void Anagrame(int k);
void ScrieSol();

int main()
{
    fin.getline(a + 1, 16);
    n = strlen(a + 1);
    sort(a + 1, a + n + 1);

    Anagrame(1);

    return 0;
}

void Anagrame(int k)
{
    if (k > n)
    {
        ScrieSol();
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        x[k] = i;

        if (!pus[i])
        {
            pus[i] = true;
            Anagrame(k + 1);
            pus[i] = false;
        }
    }
}

void ScrieSol()
{
    for (int i = 1; i <= n; ++i)
        fout << a[x[i]];
    fout << '\n';
}