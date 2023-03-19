#include <fstream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

typedef pair<int, int> PI;
typedef vector<vector<PI>> VPI;
typedef vector<bool> VB;

ifstream fin("transport2.in");
ofstream fout("transport2.out");

VPI G;
VB v;
int n, m;

void CitesteGraf();
void Dfs(int x, const int lim);
int BinarySearch();
bool Check(int g);

int main()
{
    CitesteGraf();
    fout << BinarySearch();
    
    return 0;
}

int BinarySearch()
{
    int left = 1, right = 10000;
    int gr = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (Check(mid))
        {
            gr = mid;
            left = mid + 1;
        }

        else
            right = mid - 1;
    }

    return gr;
}

void Dfs(int x, const int lim)
{
    v[x] = true;
    int y, w;
    for (PI& p : G[x])
    {
        tie(y, w) = p;
        if (!v[y] && w >= lim)
            Dfs(y, lim);
    }
}

bool Check(int g)
{
    v = VB(n + 1, false);
    Dfs(1, g);
    return v[n];
}

void CitesteGraf()
{
    fin >> n >> m;
    G = VPI(n + 1);
    v = VB(n + 1);

    int x, y, w;
    while (m--)
    {
        fin >> x >> y >> w;
        G[x].emplace_back(y, w);
        G[y].emplace_back(x, w);
    }
}