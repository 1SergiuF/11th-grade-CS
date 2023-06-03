#include <fstream>
#include <vector>
#include <utility>
#include <deque>
using namespace std;

ifstream fin("detdrum3.in");
ofstream fout("detdrum3.out");

typedef vector<pair<int, deque<int>>> VP;
const int N = 101;
int t[N];
int val[N];
int n;
int root;
int poz_max, sum_max;

vector<int> frunze;
VP sume;

bool Gasit(int nod);
void Dfs(int x, int i);

int main()
{
	fin >> n;
	for (int i = 1; i <= n; ++i)
	{
		fin >> t[i];
		if (t[i] == 0)
			root = i;
	}
	
	for (int i = 1; i <= n; ++i)
	{
		fin >> val[i];
		if (!Gasit(i))
			frunze.push_back(i);
	}
	
	sume = VP(frunze.size());
	for (size_t i = 0; i < frunze.size(); ++i)
	{
		Dfs(frunze[i], i);
		if (sume[i].first > sum_max)
		{
			sum_max = sume[i].first;
			poz_max = i;
		}
	}
		
	fout << sum_max << '\n';
	for (auto nod : sume[poz_max].second)
		fout << nod << ' ';
		
	return 0;
}

void Dfs(int x, int i)
{
	sume[i].first += val[x];
	sume[i].second.push_front(x);
	for (int f = 1; f <= n; ++f)
		if (f == t[x])
			Dfs(f, i);
}

bool Gasit(int nod)
{
	for (int i = 1; i <= n; ++i)
		if (nod == t[i])
			return true;
			
	return false;
}
