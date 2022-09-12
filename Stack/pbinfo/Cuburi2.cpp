#include <iostream>
using namespace std;

//const int N = 1001;
int main()
{
	int n;
	cin >> n;
	
	//int a[N], v[N];
	int* a = new int[n];
	int* v = new int[n];
	
	int ind = 0;
	
	cin >> a[0];
	v[0] = 0;
	
	for (int i = 1; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] > a[v[ind]])
		{
			while (a[i] > a[v[ind]] && ind >= 0)
				ind--;
		}
		
		++ind;
		v[ind] = i;
	}
	
	cout << ind + 1 << '\n';
	for (int i = 0; i <= ind; ++i)
		cout << v[i] + 1 << ' ';
	
	delete[] a;
	delete[] v;
	
	return 0;
}
