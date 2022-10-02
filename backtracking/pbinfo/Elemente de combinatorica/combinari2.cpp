#include <iostream>
using namespace std;

int x[20];
int n, p;

void Comb(int k);
bool Ok(int k);
void ScrieSol();

int main()
{
	cin >> n >> p;
	Comb(1);
	return 0;
}

void Comb(int k)
{
	if (k > p)
	{
		ScrieSol();
		return;
	}

	for (int i = x[k - 1] + 1; i <= n - p + k; ++i)
	{
		x[k] = i;
		if (Ok(k))
			Comb(k + 1);
	}
}

bool Ok(int k)
{
	if (k > 1 && (x[k] % 2 == 0 && x[k - 1] % 2 == 0))
		return false;

	return true;
}

void ScrieSol()
{
	for (int i = 1; i <= p; ++i)
		cout << x[i] << ' ';
	cout << '\n';
}