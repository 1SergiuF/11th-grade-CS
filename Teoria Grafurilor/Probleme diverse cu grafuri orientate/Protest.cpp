#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

ifstream fin("protest.in");
ofstream fout("protest.out");
int n, k; 
VVI G;
VB v;
void CitesteGraf();
void Dfs(int x);

int main()
{
    CitesteGraf();
    v = VB(n + 1, false);
    Dfs(1);
    
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
		if (v[i])
			++cnt;
			
	fout << cnt - 1;
    return 0;
}

void Dfs(int x)
{
	v[x] = true;
	for (int const& y : G[x])
		if (!v[y])
			Dfs(y);
}

void CitesteGraf()
{
    fin >> n >> k;
	G = VVI(n + 1);
	v = VB(n + 1, true);
    for (int i = 1, x; i <= k; ++i)
	{
		fin >> x;
		v[x] = false;
	}
		
    for (int i = 1, x, y; i <= n - 1; ++i)
    {
        fin >> x >> y;
        if (v[x] && v[y])
			G[x].push_back(y);	
	}
}
