#include <fstream>
#include <vector>
using namespace std;

ifstream fin("b2.in");
ofstream fout("b2.out");

int main()
{
	int n, m = 3;
	fin >> n;
	
	while (m <= n)
	{
		if (__builtin_popcount(m) == 2)
			fout << m << ' ';
		
		++m;	
	}
	
	return 0;
}
