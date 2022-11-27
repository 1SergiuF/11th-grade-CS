#include <fstream>
using namespace std;

const int N = 1001;

int n, m, k;
int d[N];

void CitesteDate();
void Greedy();

int main()
{
    CitesteDate();
    Greedy();

    return 0;
}

void CitesteDate()
{
    ifstream fin("masina.in");

    fin >> n;
    fin >> m;
    fin >> k;

    for (int i = 1; i <= k; ++i)
        fin >> d[i];

    fin.close();
}

void Greedy()
{
    ofstream fout("masina.out");

    int cnt = -1;
    int L = m;
    if (L > d[1])
    {
        L -= d[1];
        cnt = 1;
    }

    else
    {
        fout << cnt;
        return;
    }

    for (int i = 1; i <= k; ++i)
    {
        int dist = d[i + 1] - d[i];
        if (L < dist)
        {
            L += m;
            if (L < dist)
            {
                fout << -1;
                return;
            }

            ++cnt;
        }

        L -= dist;
    }

    fout << cnt;
    fout.close();
}