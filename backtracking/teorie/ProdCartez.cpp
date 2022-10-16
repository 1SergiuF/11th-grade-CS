/*
   Produsul Cartezian a n multimi

   Fie A1, A2, ..., An n multimi
   de cardinale c1, c2, ... cn

   Atunci prod. cartez a celor n multimi
   se noteaza A1 x A2 x ... x An
   si esta o multime formata din tupluri.
   Fiecare tuplu este de forma:
   {t1, t2, ..., tn} unde
   t1 apartine A1
   t2 apartine A2
   etc

*/

#include <fstream>
using namespace std;

ifstream fin("prod_cartez.in");
ofstream fout("prod_cartez.out");

int n;		  // nr de multimi
int x[15];	  // k - multimea din care aleg/ x[k] = elem ales din multimea k
int card[15]; // cardinalele multimilor
int nrsol;

void CitesteMultimi();
void ProdCartez(int k);
void ScrieSol();

int main()
{
	CitesteMultimi();
	ProdCartez(1);

	fout << nrsol << " solutii";

	return 0;
}

void CitesteMultimi()
{
	fin >> n;
	for (int i = 1; i <= n; ++i)
		fin >> card[i];
}

void ProdCartez(int k)
{
	if (k > n)
	{
		ScrieSol();
		return;
	}

	for (int i = 1; i <= card[k]; ++i)
	{
		x[k] = i;
		ProdCartez(k + 1);
	}
}

void ScrieSol()
{
	++nrsol;
	for (int i = 1; i <= n; ++i)
		fout << x[i] << ' ';
	fout << '\n';
}