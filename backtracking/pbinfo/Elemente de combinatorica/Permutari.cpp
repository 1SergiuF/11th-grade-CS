#include <fstream>

std::basic_ifstream<char> fin("permutari.in");
std::basic_ofstream<char> fout("permutari.out");

void Back(int n, int k, int x[]);
bool Ok(int k, int a[]);
bool Solutie(int n, int k);
void Afiseaza(int n, int a[]);

int main()
{
    int n;
    fin >> n;

    int* x = new int[n + 1];

    Back(n, 1, x);

    delete[] x;
    return 0;
}

void Back(int n, int k, int x[])
{
    for (int i = 1; i <= n; ++i)
    {
        x[k] = i;
        if (Ok(k, x))
        {
            if (Solutie(n, k))
                Afiseaza(n, x);
            else
                Back(n, k + 1, x);
        }
    }
}

bool Ok(int k, int a[])
{
    for (int i = 1; i < k; ++i)
        if (a[i] == a[k])
            return false;

    return true;
}

bool Solutie(int n, int k)
{
    return n == k;
}

void Afiseaza(int n, int a[])
{
    for (int i = 1; i <= n; ++i)
        fout << a[i] << ' ';

    fout << '\n';
}