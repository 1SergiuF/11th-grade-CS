#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef pair<int, int> PI;
typedef vector<PI> VP;
typedef VI::reverse_iterator RIT;

VVI G, Gt, comp;
VB v;
VI S, c;
VP vp;
set<PI> sol;
int n, m;

void CitesteGraf();
void Dfs(int x);
void DfsT(int x);
void Kosaraju();
bool SameCTC(int x, int y)
{
    return x == y;
}

int main()
{
    CitesteGraf();
    Kosaraju();

	//auto same_ctc = [](int x, int y) {return x == y;};

    for (auto& p : vp)
    {
        for (auto c : comp)
        {
			if (find(c.begin(), c.end(), p.first) != c.end() ||
				find(c.begin(), c.end(), p.second) != c.end())
				{
                    if ((find(c.begin(), c.end(), p.first) != c.end() && find(c.begin(), c.end(), p.second) == c.end()) ||
                        (find(c.begin(), c.end(), p.first) == c.end() && find(c.begin(), c.end(), p.second) != c.end()))
                            sol.insert({p.first, p.second});
				}
				
        }
    }

    cout << sol.size() << '\n';
    for (auto p : sol)
        cout << p.first << ' ' << p.second << '\n';

    return 0;
}

void CitesteGraf()
{
    cin >> n >> m;
    G = Gt = VVI(n + 1);
    v = VB(n + 1, false);

    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        vp.push_back({x, y});
        G[x].push_back(y);
        Gt[y].push_back(x);
    }
}

void Dfs(int x)
{
    v[x] = true;
    for (auto const& y : G[x])
        if (!v[y])
            Dfs(y);

    S.push_back(x);
}

void DfsT(int x)
{
    v[x] = true;
    c.push_back(x);
    for (auto const& y : Gt[x])
        if (!v[y])
            DfsT(y);
}

void Kosaraju()
{
    for (int nod = 1; nod <= n; ++nod)
        if (!v[nod])
            Dfs(nod);

    v = VB(n + 1, false);
    for (RIT it = S.rbegin(); it != S.rend(); ++it)
        if (!v[*it])
        {
            c.clear();
            DfsT(*it);
            comp.push_back(c);
        }
}

