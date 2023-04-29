#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef VI::reverse_iterator RIT;

vector<pair<int, int>> vp;
set<pair<int, int>> sol;
VVI G, GT, G_NOU, ctc;
VB v;
VI sort_top, ic, c;
int n, m, nrC;

void CitesteGraf();
void Dfs(int x);
void DfsT(int x);
void Kosaraju();
void DeterminaArce();
void ScrieGraf();

int main()
{
	CitesteGraf();
	Kosaraju();	
	sort(ctc.begin(), ctc.end());
	DeterminaArce();
	ScrieGraf();

	return 0;
}

void DeterminaArce()
{
    nrC = ctc.size();
    G_NOU = VVI(nrC + 1);
    ic = VI(n + 1);

    for (int i = 0; i < nrC; ++i)
        for (size_t j = 0; j < ctc[i].size(); ++j)
            ic[ctc[i][j]] = i + 1;

    for (int i = 1; i <= n; ++i)
        for (size_t j = 0; j < G[i].size(); ++j)
            if (ic[i] != ic[G[i][j]])
                G_NOU[ic[i]].emplace_back(ic[G[i][j]]);

    for (int i = 1; i <= nrC; ++i)
        if (G_NOU[i].size())
            sort(G_NOU[i].begin(), G_NOU[i].end());
}

void Kosaraju()
{
	v = VB(n + 1, false);
	for (int nod = 1; nod <= n; ++nod)
		if (!v[nod])
			Dfs(nod);
			
	v = VB(n + 1, false);
	for (RIT it = sort_top.rbegin(); it != sort_top.rend(); ++it)
		if (!v[*it])
		{
			c.clear();
			DfsT(*it);
			ctc.push_back(c);
		}
}

void Dfs(int x)
{
	v[x] = true;
	for (int const& y : G[x])
		if (!v[y])
			Dfs(y);
			
	sort_top.emplace_back(x);
}

void DfsT(int x)
{
	v[x] = true;
	c.push_back(x);
	for (int const& y : GT[x])
		if (!v[y])
			DfsT(y);
}

void CitesteGraf()
{
	cin >> n >> m;
	G = GT = VVI(n + 1);
	
	int x, y;
	while (m--)
	{
		cin >> x >> y;
		vp.push_back({x, y});
		G[x].emplace_back(y);
		GT[y].emplace_back(x);
	}
}

void ScrieGraf()
{
    for (int i = 1; i <= nrC; ++i)
    {
        if (G_NOU[i].size())
        {
            for (int j : G_NOU[i])
                cout << j << ' ';
        }

        else
            cout << 0;

        cout << '\n';
    }
}
