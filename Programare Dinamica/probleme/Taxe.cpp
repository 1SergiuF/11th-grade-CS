#include <fstream>
using namespace std;

ifstream cin("taxe.in");
ofstream cout("taxe.out");

const int Dim = 201;
int n, m;
int taxe[Dim][Dim], sum_taxe[Dim][Dim];
int sum_min = 4e6 + 1;

void CitesteDate();
void PlatesteTaxe();

int main()
{
    CitesteDate();
    PlatesteTaxe();

    cin.close();
    cout.close();
    return 0;
}

void CitesteDate()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> taxe[i][j];

    for(int i = 0; i <= n + 1; ++i)
        for(int j = 0; j <= m + 1; ++j)
            sum_taxe[i][j] = sum_min;
}

void PlatesteTaxe()
{
    for(int j = m; j; --j)
        for(int i = n; i; --i)
        {
            int min_curent = min(sum_taxe[i + 1][j + 1], min(sum_taxe[i][j + 1], sum_taxe[i - 1][j + 1])); 

            if(min_curent != sum_min)
                sum_taxe[i][j] = taxe[i][j] + min_curent;
            else
                sum_taxe[i][j] = taxe[i][j];
        }

    for(int i = 1; i <= n; ++i)
        sum_min = min(sum_min, sum_taxe[i][1]);

    cout << sum_min;
}