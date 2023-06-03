#include <fstream>
#include <vector>
using namespace std;

ifstream fin("b2.in");
ofstream fout("b2.out");

int Popcount(int x);
int main()
{
	int n;
	vector<int> numere;
	fin >> n;

	for (int i = 1; i <= n; ++i)
		if (Popcount(i) == 2)
			numere.push_back(i);

	for (auto const& numar : numere)
		fout << numar << ' ';
		
	return 0;
}

int Popcount(int x)
{
	int cnt = 0;

	while (x)
	{
		cnt += x & 1;
		x >>= 1;
	}

	return cnt;
}