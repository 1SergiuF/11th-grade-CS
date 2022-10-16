#include <iostream>
#include <algorithm>
using namespace std;

int n, p;
int x[30];
char ch[30];

void Comb(int k);
void ScrieSol();

std::string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
	cin >> n >> p;

	for (int i = 1; i <= n; ++i)
		ch[i] = alfabet[i - 1];

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
		Comb(k + 1);
	}
}

void ScrieSol()
{
	for (int i = 1; i <= p; ++i)
		cout << ch[x[i]];
	cout << '\n';
}