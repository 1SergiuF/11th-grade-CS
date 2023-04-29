#include <iostream>
#include <algorithm>
using namespace std;

const int N = 101;
int t[N];
int n;
int v_max;

int main()
{
	cin >> n;
	int frecv[N] {0};
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> t[i];
		frecv[t[i]]++;
		v_max = max(v_max, frecv[t[i]]);
	}
	
	for (int i = 1; i <= n; ++i)
		if (frecv[i] == v_max)
			cout << i << ' ';
	
	return 0;
}
