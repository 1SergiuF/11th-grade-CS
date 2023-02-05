#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class SegTree {
public:
	SegTree(int n) : 
		n {n}, c {vector<int>(4 * n)}, lazy {vector<int>(4 * n)}
	{}
	
	void Update(int a, int b, int color)
	{
		Update(1, 1, n, a, b, color);
	}
	
	int GetColor(int pos)
	{
		return GetColor(1, 1, n, pos);
	}
	
private:
	void Update(int x, int l, int r, int a, int b, int color)
	{
		if (a <= l && r <= b)
		{
			c[x] = color;
			lazy[x] = color;
			return;
		}
		
		PushDown(x);
		
		int m = (l + r) / 2;
		
		if (a <= m)	Update(2 * x, l, m, a, b, color);
		
		if (b > m)	Update(2 * x + 1, m + 1, r, a, b, color);
	}
	
	int GetColor(int x, int l, int r, int pos)
	{
		if (l == r)
			return c[x];
			
		PushDown(x);
		
		int m = (l + r) / 2;
		if (pos <= m)
			return GetColor(2 * x, l, m, pos);
		return GetColor(2 * x + 1, m + 1, r, pos);
	} 
	
	void PushDown(int x)
	{
		if (lazy[x])
		{
			c[2 * x]        = lazy[x];
			c[2 * x + 1]    = lazy[x];
			lazy[2 * x]     = lazy[x];
			lazy[2 * x + 1] = lazy[x];
			lazy[x] = 0;
		}
	}
	
	int n;
	vector<int> c;  
	vector<int> lazy;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T, n;
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		vector<int> li(n), ri(n); 
		vector<int> a;
		a.reserve(2 * n);
		for (int i = 0; i < n; ++i)
		{
			cin >> li[i] >> ri[i];
			a.push_back(li[i]);
			a.push_back(ri[i]);
		}

		sort(a.begin(), a.end()); 
		a.erase(unique(a.begin(), a.end()), a.end());
		
		for (int i = 0; i < n; ++i)  
			li[i] = lower_bound(a.begin(), a.end(), li[i]) - a.begin() + 1;
			
		for (int i = 0; i < n; ++i)  
			ri[i] = lower_bound(a.begin(), a.end(), ri[i]) - a.begin() + 1;
		
		int N = a.size();  
		SegTree st(N);
		
		for (int i = 0; i < n; ++i)
			st.Update(li[i], ri[i], i + 1); 
		
		set<int> colors;
		for (int pos = 1; pos <= N; ++pos)   
		{
			int color = st.GetColor(pos);
			colors.insert(color);
		}
		
		cout << colors.size() << '\n';
	}
	
	
    return 0;
}
