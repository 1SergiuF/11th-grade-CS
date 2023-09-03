#include <fstream>
#include <vector>
#include <tuple>
using namespace std;

ifstream fin("bomboane.in");
ofstream fout("bomboane.out");

const int N = 1001;
int n, a[N];
int v_max = -1, v_min = N;
int poz_max = 0, poz_min = 0;
int rez;
vector<tuple<int, int, int>> SDB;

void AflaMaxMin();
bool SuntAranjate();

int main()
{
	int key = 0;
	int sum = 0;

	fin >> n;
	for (int i = 1; i <= n; ++i)
	{
		fin >> a[i];
		sum += a[i];
	}

	if (sum % n != 0)
		fout << -1;
	else
	{
		key = sum / n;
		int k = 0;

		while (!SuntAranjate())
		{
			AflaMaxMin();
			k = key - v_min;

			a[poz_max] -= k;
			a[poz_min] += k;

			++rez;
			SDB.push_back(make_tuple(poz_max, poz_min, k));
		}

		fout << rez << '\n';

		for (auto const& t : SDB)
		{
			fout << get<0>(t) << ' '
				 << get<1>(t) << ' '
				 << get<2>(t) << '\n';
		}
	}

	return 0;
}

void AflaMaxMin()
{
	v_max = -1, v_min = N;
	poz_max = 0, poz_min = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (v_max < a[i])
		{
			v_max = a[i];
			poz_max = i;
		}

		if (v_min > a[i])
		{
			v_min = a[i];
			poz_min = i;
		}
	}
}

bool SuntAranjate()
{
	int cnt = 0;
	for (int i = 1; i < n; ++i)
		if (a[i] == a[i + 1])
			++cnt;

	if (cnt == n - 1) return true;
	else return false;
}