#include <fstream>
using namespace std;

ifstream fin("bifrunze.in");
ofstream fout("bifrunze.out");

int main()
{
	int n;
	fin >> n;

	int x, st, dr;
	for (int i = 1; i <= n; ++i)
	{
		fin >> x >> st >> dr;
		if (!st && !dr)
			fout << i << ' ';
	}

	return 0;
}