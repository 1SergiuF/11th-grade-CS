#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("plopi1.in");
ofstream fout("plopi1.out");

const int N = 1003;
int n, a[N];
int L[N];
int Lmax;

void CitesteDate();
int Dinamica();

int main()
{
	CitesteDate();
	fout << Dinamica();

	return 0;
}

void CitesteDate()
{
	fin >> n;
	for (int i = 1; i <= n; ++i)
		fin >> a[i];
}

int Dinamica()
{
	L[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		int mx = 0;
		for (int j = 1; j < i; ++j)
			if (a[j] > a[i] && L[j] > mx)
				mx = L[j];

		L[i] = mx + 1;
		Lmax = max(Lmax, L[i]);
	}

	return n - Lmax;
}