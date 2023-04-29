#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> G;
int T, n, m;

void ReadData();
void Solve();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		ReadData();
		Solve();
	}
	
	return 0;
}

void Solve()
{
	int aux = m - 1;
	vector<int> sol;
	for (int i = 1; i <= m - 1; ++i)
	{
		for (auto const& val : G[i])
		{
			int cnt = 0;
			for (int j = i + 1; j <= m; ++j)
			{
				if (find(G[j].begin(), G[j].end(), val) != G[j].end())
					break;
				else
					++cnt;
			}
			
			if (cnt == aux)
			{
				sol.push_back(val);
				break;
			}				
		}
		
		aux -= 1;
	}
	
	if (sol.empty()) cout << -1 << '\n';
	else
	{
		sol.push_back(G[m][0]);
		for (auto const& val : sol)
			cout << val << ' ';
		cout << '\n';
	}
}

void ReadData()
{
	cin >> m;
	G = vector<vector<int>>(m + 1);
	
	for (int i = 1; i <= m; ++i)
	{
		cin >> n;
		int x;
		for (int j = 1; j <= n; ++j)
		{
			cin >> x;
			G[i].push_back(x);
		}
	}
}
