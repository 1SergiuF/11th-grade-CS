#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("difsub.in");
ofstream fout("difsub.out");

const int N = 1001;
int t[N];
int root;

struct Nod {
	int X;
	int st, dr;

} arb[N];

int n;
int sum;

void CitesteArbore();
void InOrdine(int nod);

int main()
{
	CitesteArbore();

	int sum_st = 0, sum_dr = 0;
	InOrdine(arb[root].st);
	sum_st = sum;

	sum = 0;
	InOrdine(arb[root].dr);
	sum_dr = sum;

	fout << abs(sum_st - sum_dr);

	return 0;
}

void CitesteArbore()
{
	fin >> n;
	int X, st, dr;
	for (int i = 1; i <= n; ++i)
	{
		fin >> X >> st >> dr;
		arb[i] = {X, st, dr};

		if (st) t[st] = i;
		if (dr) t[dr] = i;
	}

	for (int i = 1; i <= n; ++i)
		if (t[i] == 0)
		{
			root = i;
			break;
		}
}

void InOrdine(int nod)
{
	if (!nod) return;

	InOrdine(arb[nod].st);
	sum += arb[nod].X;
	InOrdine(arb[nod].dr);
}