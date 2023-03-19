#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

ifstream fin("ubuntzei.in");
ofstream fout("ubuntzei.out");

struct Pair {
	int dist, nod;
	
	bool operator < (Pair const& p) const noexcept
	{
		return dist > p.dist;
	}
};

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;

#define Inf 0x3f3f3f3f
VI C, d;
VVI D, dp;
VVPII G;
int n, m, K;

void ReadGraph();
void Dijkstra(int S, VI& d);
int Dinamica();

int main()
{
    ReadGraph();
    Dijkstra(1, d);
    fout << (!K ? d[n] : Dinamica());    
    return 0;
}

int Dinamica()
{
    for (int i = 0; i < K; ++i)
        Dijkstra(C[i], D[i]);

    for (int i = 0; i < K; ++i)
        dp[1 << i][i] = d[C[i]];

    for (int i = 1; i < (1 << K); ++i)
        for (int j = 0; j < K; ++j)
            if (i & (1 << j))
                for (int k = 0; k < K; ++k)
                    if (!(i & (1 << k)))
                        dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + D[j][C[k]]);

    int res(Inf);
    for (int i = 0; i < K; ++i)
        res = min(res, dp[(1 << K) - 1][i] + D[i][n]);

    return res;
}

void Dijkstra(int S, VI& d)
{
    priority_queue<Pair> Q;
    d = VI(n + 1, Inf);
    d[S] = 0;
    Q.push({0, S});
    int x, dx, y, w;

    while (!Q.empty())
    {
        x  = Q.top().nod;
        dx = Q.top().dist;
        Q.pop();

        if (d[x] < dx) continue;

        for (PII& p : G[x])
        {
            y = p.first;
            w = p.second;
            if (d[y] > d[x] + w)
            {
                d[y] = d[x] + w;
                Q.push({d[y], y});
            }
        }
    }
}

void ReadGraph()
{
    fin >> n >> m >> K;
    C = VI(K);
    D = VVI(K);
    G = VVPII(n + 1);
    dp = VVI(1 << K, VI(K, Inf));

    for (int i = 0; i < K; ++i)
        fin >> C[i];

    for (int i = 1, x, y, w; i <= m; ++i)
    {
        fin >> x >> y >> w;
        G[x].emplace_back(y, w);
        G[y].emplace_back(x, w);
    }
}