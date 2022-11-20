#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("lipsa.in");
ofstream fout("lipsa.out");

int n, x;

int main()
{
	int s = 0, s_lipsa = 0;

	fin >> n;
	for (int i = 1; i <= n; ++i)
		s += i;

	for (int i = 1; i < n; ++i)
	{
		fin >> x;
		s_lipsa += x;
	}

	fout << s - s_lipsa;

	return 0;
}