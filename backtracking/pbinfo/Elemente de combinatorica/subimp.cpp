#include <iostream>
using namespace std;

int x[20];
int n;

void Subm(int k);
void ScrieSol(int k);
bool Ok(int k);

int main()
{
	cin >> n;
	Subm(1);
	return 0;
}

void Subm(int k)
{
	if (k > n) return;

	for (int i = x[k - 1] + 1; i <= n; ++i)
	{
		x[k] = i;
		ScrieSol(k);
		Subm(k + 1);
	}
}

void ScrieSol(int k)
{
	int cnt = 0;
	for (int i = 1; i <= k; ++i)
		++cnt;

	if (cnt % 2 == 1)
	{
		for (int i = 1; i <= k; ++i)
			cout << x[i] << ' ';
		cout << '\n';		
	}
}