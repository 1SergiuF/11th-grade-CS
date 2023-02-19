#include <fstream>
#include <vector>
using namespace std;

ifstream fin("veriflant.in");
ofstream fout("veriflant.out");

#define N 101
vector<int> G[N];
int n, m, k, p;
int L[2 * N];

int VerifLant(int k, int L[]);
void CitesteGraf();

int main()
{
	CitesteGraf();
	return 0;
}

int VerifLant(int k, int L[])
{
	for (int i = 1; i < k; ++i)
	{
		bool ok = false;
		for (auto const& g : G[L[i]])
			if (g == L[i + 1])
				ok = true;

		if (!ok) return 0;
	}

	int c[101] {0};
	for (int i = 1; i <= k; ++i)
		c[L[i]]++;

	for (int i = 1; i <= n; ++i)
		if (c[i] > 1)
			return 2;

	return 1;
}

void CitesteGraf()
{
	fin >> n >> m;
	for (int i = 1, x, y; i <= m; ++i)
	{
		fin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	fin >> k;
	for (int i = 1; i <= k; ++i)
	{
		fin >> p;
		for (int j = 1; j <= p; ++j)
			fin >> L[j];

		if (!VerifLant(p, L)) fout << "NU\n";
		else if (VerifLant(p, L) == 1) fout << "ELEMENTAR\n";
		else fout << "NEELEMENTAR\n";
	}
}