#include <fstream>
using namespace std;

ifstream fin("part_mult.in");
ofstream fout("part_mult.out");

int n;
int x[20];

int nrsol;

void PartMult(int k, int mx);
void ScrieSol(int subm);

int main()
{
    fin >> n;
    PartMult(1, 0);
    fout << nrsol << " solutii";
    return 0;
}

void PartMult(int k, int mx)
{
    if (k > n)
    {
        ScrieSol(mx);
        return;
    }

    for (int i = 1; i <= mx + 1; ++i)
    {
        x[k] = i;
        PartMult(k + 1, max(i, mx));
    }
}

void ScrieSol(int subm)
{
    ++nrsol;

    for (int s = 1; s <= subm; ++s)
    {
        fout << "{ ";
        for (int i = 1; i <= n; ++i)
            if (x[i] == s)
                fout << i << ' ';
        fout << "} ";
    }

    fout << '\n';
}