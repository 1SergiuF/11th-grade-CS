#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 3;

int main()
{
	int n;
	long long a[N];
	long long vmax1 = -1 * (1e6 + 1), vmax2 = -1 * (1e6 + 1), vmin_negativ1 = 1e6 + 1, vmin_negativ2 = 1e6 + 1;
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		
		if (a[i] > 0)
			vmax1 = max(vmax1, a[i]);
		else
			if (a[i] < 0)
				vmin_negativ1 = min(vmin_negativ1, a[i]);
	}
	
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] > 0 && a[i] < vmax1)
			vmax2 = max(vmax2, a[i]);
		else
			if (a[i] < 0 && a[i] > vmin_negativ1)
				vmin_negativ2 = min(vmin_negativ2, a[i]);
	}
	
	if (vmax1 * vmax2 > vmin_negativ1 * vmin_negativ2)
		cout << vmax1 * vmax2;
	else
		cout << vmin_negativ1 * vmin_negativ2;
		
	return 0;
}
