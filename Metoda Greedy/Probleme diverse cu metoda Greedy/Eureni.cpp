#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("eureni.in");
ofstream fout("eureni.out");

int S, n, e;
void Greedy();

int main()
{
    fin >> S >> n >> e;
    Greedy();

    return 0;
}

void Greedy()
{
    int val_banc = 1;
    int nr_banc = 0;
    int total_bancnote = 0;

    while (n--)
        val_banc *= e;

    while (S)
    {
        nr_banc = S / val_banc;

        while (nr_banc == 0)
        {
            val_banc /= e;
            nr_banc = S / val_banc;
        }

        fout << val_banc << ' ' << nr_banc << '\n';
        S -= val_banc * nr_banc;
        total_bancnote += nr_banc;
    }

    fout << total_bancnote;
}