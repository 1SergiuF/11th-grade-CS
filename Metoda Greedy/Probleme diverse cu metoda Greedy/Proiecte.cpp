#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("proiecte.in");
ofstream fout("proiecte.out");

struct Proiect {
	
	int t, ord;
	
	bool operator < (Proiect const& ob) const noexcept
	{
		return t < ob.t;
	}
};

const int N = 1001;
int n;
Proiect a[N];

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
	fin >> n;
	for (int i = 1; i <= n; ++i)
	{
		fin >> a[i].t;
		a[i].ord = i;
	}
	
	sort(a + 1, a + n + 1);
}

void Greedy()
{	
	for (int i = 1; i <= n; ++i)
		fout << a[i].ord << ' ';
}
