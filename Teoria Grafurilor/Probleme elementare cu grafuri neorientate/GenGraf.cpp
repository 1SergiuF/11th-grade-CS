#include <fstream>
using namespace std;

ifstream fin("gengraf.in");
ofstream fout("gengraf.out");

bool a[10][10];
int x[101];
int n;
int m;

void GenereazaGraf(int k);
void Afiseaza();

int main()
{
	fin >> n;
	m = n * (n - 1) / 2;
	int p = 1 << m;
	
	fout << p << '\n';
	GenereazaGraf(1);
	
	return 0;
}

void GenereazaGraf(int k)
{
    for(int i = 0 ; i <= 1 ; i++)
    {
        x[k] = i;
        if(k == m) Afiseaza();
        else GenereazaGraf(k + 1);
    }
}

void Afiseaza()
{
	for (int i = 1, k = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			a[i][j] = a[j][i] = x[k];
			k++;
		}
		
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			fout << a[i][j] << ' ';
		fout << '\n';
	}
	
	fout << '\n';
}
