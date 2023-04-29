#include <iostream>
#include <algorithm>
using namespace std;

const int N = 101;
string Solve(int n, int a[], int b[]);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T;
	int n;
	int a[N], b[N];
	
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
			
		for (int j = 1; j <= n; ++j)
			cin >> b[j];
			
		cout << Solve(n, a, b);
	}
	
	return 0;
}

string Solve(int n, int a[], int b[])
{
	if (n == 1) return "Yes\n";
	
	int a_max = -1, b_max = -1;
	int a_poz_max = 0, b_poz_max = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		if (a_max <= a[i])
		{
			a_max = a[i];
			a_poz_max = i;
		}
		
		if (b_max <= b[i])
		{
			b_max = b[i];
			b_poz_max = i;
		}
	}
	
	if (a[n] == a_max && b[n] == b_max)
		return "Yes\n";
		
	if (a[n] == b[n] && (a[n] != a_max || b[n] != b_max))
		return "No\n";
		
	else
	{
		if (a_poz_max < b_poz_max)
		{
			for (int p = a_poz_max + 1; p <= n; ++p)
			{
				int aux = a[p];
				a[p] = b[p];
				b[p] = aux;
			}
		}
		
		else
		{
			for (int p = b_poz_max + 1; p <= n; ++p)
			{
				int aux = a[p];
				a[p] = b[p];
				b[p] = aux;
			}			
		}
	}
	
	int a_max2 = -1, b_max2 = -1;
	for (int i = 1; i <= n; ++i)
	{
		a_max2 = max(a_max2, a[i]);
		b_max2 = max(b_max2, b[i]);
	}
	
	if (a[n] == a_max2 && b[n] == b_max2)
		return "Yes\n";

	return "No\n";
}
