#include <fstream>
#include <string>
#include <cmath>
using namespace std;

ifstream fin("nrsufix.in");
ofstream fout("nrsufix.out");

int main()
{
    int x;
    int a;

    fin >> x;
    int P = 1;
    while (pow(10, P) <= x)
    {
        ++P;
    }

    int POW = pow(10, P);
    int n = 0;

    while (fin >> a)
    {
        if (a % POW == x)
            n = a;
    }

    if (!n) fout << "nu exista";
    else fout << n;

    return 0;
}