#include <fstream>
using namespace std;

ifstream fin("sirab.in");
ofstream fout("sirab.out");

int n, S;
int x[20];

void Back(int k);
void ScrieSol();
bool Ok(int k);

int main()
{
    fin >> S >> n;
    Back(1);

    return 0;
}

void Back(int k)
{
    if (k > n)
    {
        ScrieSol();
        return;
    }

    for (int i = 1; i <= S; ++i)
    {
        x[k] = i;
        if (Ok(k))
            Back(k + 1);
    }
}

void ScrieSol()
{
    // int cnt = 0;
    // int i = 1, j = 1;
    // while (i <= n)
    // {
    //     while (j <= n)
    //     {
    //         if (x[i] < x[j])
    //         {
    //             if ((x[i] + x[j]) % (x[j] - x[i]) == 0)
    //                 ++cnt;
    //         }

    //         else
    //         {
    //             if ((x[i] + x[j]) % (x[i] - x[j]) == 0)
    //                 ++cnt;
    //         }

    //         ++j;            
    //     }

    //     ++i;
    // }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         if (x[i] < x[j])
    //         {
    //             if ((x[i] + x[j]) % (x[j] - x[i]) == 0)
    //                 ++cnt;
    //         }

    //         else
    //         {
    //             if ((x[i] + x[j]) % (x[i] - x[j]) == 0)
    //                 ++cnt;
    //         }
    //     }
    // }
    //if (cnt == S - n)
   // {
        for (int i = 1; i <= n; ++i)
            fout << x[i] << ' ';
        fout << '\n';
   // }
}

bool Ok(int k)
{
    int cnt = 0;
    for (int i = 1; i < k; ++i)
        if (x[i] == x[k])
            return false;

    int i = 1, j = 1;
    while (i <= n)
    {
        while (j <= n)
        {
            if (x[i] < x[j])
            {
                if ((x[i] + x[j]) % (x[j] - x[i]) == 0)
                    ++cnt;
            }

            else
            {
                if ((x[i] + x[j]) % (x[i] - x[j]) == 0)
                    ++cnt;
            }

            ++j;            
        }

        ++i;
    }

    cnt = cnt - 1;
    if (cnt != S - n) return false;
    return true;
}