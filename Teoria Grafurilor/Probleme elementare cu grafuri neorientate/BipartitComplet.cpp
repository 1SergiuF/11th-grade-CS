#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("bipartitcomplet.in");
ofstream fout("bipartitcomplet.out");

#define N 101
int n, k;
bool a[101][101];
int A[N];
int B[N];
int cnt;
int nr_elem_A;

void CitesteGraf();
void AdaugaInB();

int main()
{
    CitesteGraf();
    AdaugaInB();
    
    for (int i = 1; i <= nr_elem_A; ++i)
    {
		for (int j = 1; j <= cnt; ++j)
			a[A[i]][B[j]] = a[B[j]][A[i]] = true;
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			fout << a[i][j] << ' ';
			
		fout << '\n';
	}
	
    return 0;
}

void AdaugaInB()
{
	bool ok = false;
    for (int i = 0; i <= n; ++i)
    {
		for (int j = 1; j <= nr_elem_A; ++j)
			if (i == A[j])
			{
				ok = false;
				break;
			}
				
		if (ok)
			B[++cnt] = i;
		
		ok = true;
	}
}

void CitesteGraf()
{
    fin >> n;
    fin >> k;
    for (int i = 1; i <= k; ++i)
    {
		fin >> A[i];
		++nr_elem_A;
	}
}
