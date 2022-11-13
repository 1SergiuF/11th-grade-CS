#include <fstream>
using namespace std;

ifstream fin("partitiimultime3.in");
ofstream fout("partitiimultime3.out");

int n, m;
int x[20];
int nrsol;

void PartMult(int k, int mx);
void ScrieSol(int subm);
bool Ok(int k);

int main()
{
    fin >> n >> m;
    PartMult(1, 0);

    if (!nrsol) fout << "IMPOSIBIL";

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
       // if (Ok(mx))
            PartMult(k + 1, max(i, mx));
    }
}

void ScrieSol(int subm)
{
    ++nrsol;

    int cnt = 0, cnt2 = 0, cnt3 = 0;
    for (int s = 1; s <= subm; ++s)
    {
        ++cnt;
        for (int i = 1; i <= n; ++i)
            ++cnt2;

        if (cnt2 / 2 == m)
        {
            ++cnt3;
            cnt2 = 0;
        }
    }

    if (cnt == m && cnt3 == cnt)
    {
        for (int s = 1; s <= subm; ++s)
        {
            for (int i = 1; i <= n; ++i)
                if (x[i] == s)
                    fout << i;
            fout << '*';
        }

        fout << ' ' << cnt3 << '\n';
    }
}

// bool Ok(int k)
// {
//     int cnt = 0;
//     for (int s = 1; s <= k; ++s)
//         ++cnt;

//     if (cnt != m) return false;

//     return true;
// }