#include <fstream>
using namespace std;

ifstream fin("produscartezian1.in");
ofstream fout("produscartezian1.out");

int n, p;
int x[10];

void Cartez(int k);
void ScrieSol();

int main()
{
	fin >> n >> p;
	Cartez(1);
	return 0;
}

void Cartez(int k)
{
	if (k > p)
	{
		ScrieSol();
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		x[k] = i;
		Cartez(k + 1);
	}
}

void ScrieSol()
{
	for (int i = 1; i <= p; ++i)
		fout << x[i] << ' ';
	fout << '\n';
}