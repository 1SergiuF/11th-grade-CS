#include <fstream>
using namespace std;

ifstream fin("permutari1.in");
ofstream fout("permutari1.out");

int x[15];
bool pus[15];
int n;

void Perm(int k);
void ScrieSol();

int main()
{
    fin >> n;
    Perm(n);

    return 0;
}

void Perm(int k)
{
    if (k < 1)
    {
        ScrieSol();
        return;
    }

    for (int i = n; i >= 1; --i)
    {
        x[k] = i;
        if (!pus[i])
        {
            pus[i] = true;
            Perm(k - 1);
            pus[i] = false;
        }
    }
}

void ScrieSol()
{
    for (int i = n; i >= 1; --i)
        fout << x[i] << ' ';
    fout << '\n';
}
