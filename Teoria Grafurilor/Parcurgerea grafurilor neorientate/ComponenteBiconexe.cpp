#include <vector>
#include <set>
#include <fstream>
#include <stack>
#include <tuple>
#include <unordered_set>
using namespace std;

ifstream fin("componentebiconexe.in");
ofstream fout("componentebiconexe.out");

using PI  = pair<int, int>;
using SI  = set<int>;
using SSI  = set<SI>;
using VB  = vector<bool>;
using VI  = vector<int>;
using VVI = vector<VI>;

typedef SI::iterator it;
VVI G;   
SSI cbc; 
SI c;  
VB v;
VI index, low; 
VI niv;
int nr;
VI t;          
int idx;      
stack<PI> stk; 
SI artic;
vector<pair<int, int>> punti;
int n, m, op;

void CitesteGraf();
void CompBiConexe();
void Tarjan(int x);
void ExtractCBC(int x, int y);

void ScrieCBC();
void ScriePuncteArt();
void ScriePunti();

int main()
{
	CitesteGraf();
	CompBiConexe();

    switch(op) {
        case 1:
            ScrieCBC();
            break;

        case 2:
            ScriePuncteArt();
            break;

		case 3:
			ScriePunti();
			break;
    }

	return 0;
}

int root;
void CompBiConexe()
{
	for (int x = 1; x <= n; ++x)
		if (!v[x])
		{
			root = x;
			nr = 0;
			Tarjan(x);
			if (x == root && nr > 1)
				artic.insert(x);
		}
}

void Tarjan(int x)
{
	v[x] = true;
	index[x] = low[x] = ++idx;
	niv[x] = niv[t[x]] + 1;
	if (niv[x] == 2) nr++;
	for (const int& y : G[x])
	{
		if (y == t[x]) continue; 
		
		if (!v[y]) 
		{
			t[y] = x;
			stk.emplace(x, y);
			
			Tarjan(y);
			low[x] = min(low[x], low[y]);
			
            if (low[y] >= index[x])
            {
                ExtractCBC(x, y);
                if (x != root)
                    artic.insert(x);
            } 
		}
		else 
			low[x] = min(low[x], index[y]);	
	}	
}

void ExtractCBC(int x, int y)
{
	c.clear();
    int a, b;
	while (!stk.empty())
	{
		tie(a, b) = stk.top();
		stk.pop();
		c.insert(a); c.insert(b);
		if (a == x && b == y)
			break;
	}
	
	cbc.insert(c);   
}

void CitesteGraf()
{
    fin >> op;
	fin >> n >> m;
	G = VVI(n + 1); 
	v = VB(n + 1);
	index = low = t = niv = VI(n + 1);
	int x, y;
	while (m--)
	{
		fin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
}

void ScrieCBC()
{
    fout << cbc.size() << '\n';
    for (auto c : cbc)
    {
        fout << c.size() << ' ';
        for (int nod : c)
            fout << nod << ' ';
        fout << '\n';
    }
}

void ScriePuncteArt()
{
    fout << artic.size() << '\n';
    for (int x : artic)
	    fout << x << ' ';    
}

void ScriePunti()
{
    for (auto c : cbc)
    {
		if (c.size() == 2)
		{
			for (auto nod : c)
				fout << nod << ' ';
			fout << '\n';
		}
    }	
}