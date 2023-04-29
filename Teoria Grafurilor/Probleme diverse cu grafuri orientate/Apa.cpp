#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

#define INF INT_MAX
#define Nmax 300
typedef vector<vector<int>> VVI;

ifstream fin("apa.in");
ofstream fout("apa.out");
VVI G;	// graful
vector<int> cap[Nmax];   // matricea de capacitati

int s, t;	// s - nodul sursa
			// t - nodul destinatie
			
int n;	// nr de noduri

void ReadData();
int Bfs(vector<int>& parent);
int MaxFlow();

int main()
{
	ReadData();
	fout << MaxFlow();
		
	return 0;
}

int Bfs(vector<int>& parent)
{
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int>> Q;
	Q.push({s, INF});
	
	while (!Q.empty())
	{
		int x    = Q.front().first;
		int flow = Q.front().second;
		Q.pop();
		
		for (auto const& y : G[x])
			if (parent[y] == -1 && cap[x][y])
			{
				parent[y]    = x;
				int new_flow = min(flow, cap[x][y]);
				if (y == t)
					return new_flow;
					
				Q.push({y, new_flow});
			}
	}
	
	return 0;
}

int MaxFlow()
{
	int flow = 0;
	vector<int> parent(n + 1);
	int new_flow;
	
	while (new_flow = Bfs(parent))
	{
		flow += new_flow;
		int x = t;
		while (x != s)
		{
			int prev = parent[x];
			cap[prev][x] -= new_flow;
			cap[x][prev] += new_flow;
			x = prev;
		}
	}
	
	return flow;
}

void ReadData()
{
	fin >> n;
	s = 1;
	t = n;
	G   = VVI(n + 1);
	int x, y, w;
	while (fin >> x >> y >> w)
	{
		G[x].push_back(y);
		G[y].push_back(x);
	}
}
