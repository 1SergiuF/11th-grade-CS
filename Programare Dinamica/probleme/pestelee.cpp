#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

ifstream fin("pestelee.in");
ofstream fout("pestelee.out");

enum Arhipelag {
	apa,
	uscat
};

struct Cel {
	int i, j;
};

const int Dim = 501,
		  Inf = 0x3f3f3f3f,
		  di[] = {-1, 0, 1, 0},
		  dj[] = {0, 1, 0, -1},
		  MOD = 10007;

bool L[Dim][Dim];
int c[Dim][Dim];
int dr[Dim][Dim];

int n, m, x1, y1, x2, y2, r;
bool ok = false;

void CitesteDate();
void Lee(int ip, int jp, int c[][Dim]);
bool Ok(int i, int j);

int main()
{
	CitesteDate();
	Lee(x1, y1, c);
	
	if (ok)
	{
		int sol = (r == 1) ? c[x2][y2] : dr[x2][y2];	
		fout << sol;
	}
	
	else
		fout << 0;
}

void CitesteDate()
{
	fin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			fin >> L[i][j];

	fin >> x1 >> y1 >> x2 >> y2;

	fin >> r;
}

#define iv (i + di[d])
#define jv (j + dj[d])

void Lee(int ip, int jp, int c[][Dim])
{
	Cel Q[Dim * Dim];
	int p = 0, u = -1;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			c[i][j] = Inf;
			
	c[x1][y1] = 1;
	dr[x1][y1] = 1;
	Q[++u] = { x1, y1 };
	
	while (p <= u)
	{
		int i = Q[p].i;
		int j = Q[p].j;
		p++;
		
		for (int d = 0; d < 4; ++d)
		{
			if (Ok(iv, jv) && c[iv][jv] > c[i][j] + 1)
			{
				ok = true;
				c[iv][jv] = c[i][j] + 1;
				dr[iv][jv] = (dr[iv - 1][jv] +
						    dr[iv][jv + 1] +
						    dr[iv + 1][jv] +
						    dr[iv][jv - 1]) % MOD;
						    
				Q[++u] = { iv, jv };
			}
		}
	}
}

bool Ok(int i, int j)
{
	if (i < 1 || i > n || j < 1 || j > m)
		return false;

	if (L[i][j] == uscat)
		return false;

	return true;
}
