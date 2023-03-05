#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("gears.in");
ofstream fout("gears.out");

typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;

VVI G;
VB v;
int n, p;
bool vb[101];

void CitesteGraf();
void Bfs(int x);

int main()
{
	CitesteGraf();
	vb[p] = true;
	Bfs(p);

	for (int i = 1; i <= n; ++i)
		fout << (vb[i] ? 'D' : 'S');

	return 0;
}

void Bfs(int x)
{
	queue<int> Q;
	v[x] = true;
	Q.push(x);

	while (!Q.empty())
	{
		x = Q.front();
		Q.pop();

		for (auto const& y : G[x])
		{
			if (v[y]) continue;
			v[y] = true;
			vb[y] = vb[x] ? false : true;
			Q.push(y);
		}
	}
}

void CitesteGraf()
{
	fin >> n >> p;
	G = VVI(n + 1);
	v = VB(n + 1);
	int x, y;
	for (int i = 1; i <= n - 1; ++i)
	{
		fin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
}