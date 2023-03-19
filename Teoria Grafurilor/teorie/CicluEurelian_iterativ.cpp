/**
 Determionarea unui ciclu eulerian
 Varianta iterativa Dfs

*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <tuple>
using namespace std;

ifstream fin("ciclueuler.in");
ofstream fout("ciclueuler.out");

using PI  = pair<int, int>;
using VP  = vector<PI>;
using Iter= VP::iterator;
using VB  = vector<bool>;
using VI  = vector<int>;
using VVP = vector<VP>;

VVP G;  /// graful -
int n, m;
VB v;   /// marcam muchiile vizitate
VI ce;  /// ciclul eulerian determinat

void CitesteGraf();
bool GrafEulerian();
void CicluEuler(int x);
void ScrieCicluEulerian();

int main()
{
    CitesteGraf();
    if (!GrafEulerian())
        fout << "Nu este graf eulerian!";
    else
    {
        CicluEuler(1);
        ScrieCicluEulerian();
    }
}

void CicluEuler(int x)
{
    vector<Iter> p(n + 1);
    for (int x = 1; x <= n; ++x)
        p[x] = G[x].begin();

    stack<int> stk; /// plasam nodurile
    stk.push(x);
    int y, e;
    while (!stk.empty())
    {
        x = stk.top();
        if (p[x] == G[x].end()) /// nu mai sunt vecini ne explorati
        {
            ce.push_back(x);
            stk.pop();
        }
        else
        {
            tie(e, y) = *p[x]++;
            if (v[e]) continue;
            v[e] = true;
            stk.push(y);
        }
    }
}

void ScrieCicluEulerian()
{
    for (int x : ce)
        fout << x << ' ';
}

void CitesteGraf()
{
    fin >> n >> m;
    G = VVP(n + 1);
    v = VB(m + 1);

    int x, y;
    for (int e = 1; e <= m; ++e)
    {
        fin >> x >> y;
        G[x].emplace_back(e, y);
        G[y].emplace_back(e, x);
    }
}

bool GrafEulerian()
{
    for (int x = 1; x <= n; ++x)
        if (G[x].size() % 2 == 1) // nr de muchii incidente - impar
            return false;
    return true;
}