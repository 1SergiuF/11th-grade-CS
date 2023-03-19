#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef VI::iterator IT;

ifstream fin("relatii.in");
ofstream fout("relatii.out");

VVI adj;
VI S;
VB v;
int n, m;

void CitesteGraf();
void Dfs(int x);
void SortTop();

int main()
{
	CitesteGraf();
	SortTop();
	return 0;
}

void SortTop()
{
	v = VB(n + 1, false);
	for (int nod = 1; nod <= n; ++nod)
		if (!v[nod])
			Dfs(nod);

	for (IT it = S.begin(); it != S.end(); ++it)
		fout << static_cast<char>(*it+96);
}

void Dfs(int x)
{
	v[x] = true;
	for (int const& y : adj[x])
		if (!v[y])
			Dfs(y);

	S.push_back(x);
}

void CitesteGraf()
{
	fin >> n >> m;
	adj = VVI(n + 1);
	char v1, v2, op;
	while (m--)
	{
		fin >> v1 >> op >> v2;
		if (op == '<')
            adj[v2-96].push_back(v1-96);
        else
            adj[v1-96].push_back(v2-96);
	}
}