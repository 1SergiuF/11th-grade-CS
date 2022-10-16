/**
  Problema restaurantului
*/

#include <fstream>
#include <string>
using namespace std;

ifstream fin("restaurant.in");
ofstream fout("restaurant.out");

int n;		  		// nr de multimi
int x[20];		    // k - multimea din care aleg/ x[k] = elem ales din multimea k
int card[20]; 		// cardinalele multimilor
string p[50][50];   // produsele
int nrsol;

void CitesteMultimi();
void ProdCartez(int k);
void ScrieSol();

int main()
{
	CitesteMultimi();
	ProdCartez(1);

	fout << nrsol << " solutii";
}

void CitesteMultimi()
{
	fin >> n;
	for (int i = 1; i <= n; ++i) // pt fiecare multime
	{
		fin >> card[i];
		fin.get();
		for (int j = 1; j <= card[i]; ++j)
			getline(fin, p[i][j]); // citim al j-lea item din categoria i
	}
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
		fout << p[i][x[i]] << ' ';
	fout << '\n';
}