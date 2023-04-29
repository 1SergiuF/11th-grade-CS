#include <fstream>
#include <queue>
#include <bitset>
#include <tuple>
using namespace std;

const int Nmax = 1001, Inf = 1 << 30;

ifstream fin("prim.in");
ofstream fout("prim.out");

struct Edge {	
	Edge(int node, int key) : node {node}, key {key}
	{}
	
    const bool operator < (const Edge &e) const
    {
        return key > e.key;
    } 
    int node, key;
};

using VI = vector<int>;
using VP = vector<pair<int, int>>;
using VVE = vector<vector<Edge>>;

VVE G;
VP apm;
VI key, t;

int n;
long long cost_apm;
bitset<Nmax + 1> v;

void CitesteGraf();
void Prim (int x);
void ScrieSol();

int main()
{
	CitesteGraf();   
	Prim(1);
	ScrieSol();

    return 0;
}

void Prim (int x)
{
	priority_queue<Edge> Q;
    key = VI(n + 1, Inf);
    t = VI(n + 1);
    
    key[x] = 0;
    Q.push({x, 0});

    while (!Q.empty() )
    {
        x = Q.top().node;
        Q.pop();  
        if (v[x]) continue; 
        v[x] = 1;  
        apm.emplace_back(t[x], x); 
		cost_apm += key[x];    
		    
        for (auto p : G[x])
        {   
            int y = p.node;
            int w = p.key;
			if ( v[y] ) continue;

            if ( key[y] > w )
            {
                key[y] = w;
                t[y] = x;
                Q.emplace(y, key[y]);
            }
		}		
    }
}

void CitesteGraf()
{
	int a, b, w, m;	
	fin >> n >> m;
	G = VVE(n + 1);
    while (m--)  
    {
        fin >> a >> b >> w;
        G[a].emplace_back(b, w);
        G[b].emplace_back(a, w);
    }
}

void ScrieSol()
{
	
	fout << cost_apm << '\n';
	for (size_t i = 1; i <= apm.size(); ++i)
		fout << t[i] << ' ';
}