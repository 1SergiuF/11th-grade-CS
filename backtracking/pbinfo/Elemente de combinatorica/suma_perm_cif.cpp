#include <iostream>
#include <algorithm>
using namespace std;

int x[15], a[15];
int n, m, cnt;
long long S;
bool pus[15];

void CitesteDate();
void Perm(int k);
void Suma();

int main()
{
	CitesteDate();
	Perm(1);

	cout << S;
}

void CitesteDate()
{
	cin >> n;
	m = n;

	while (m)
	{
		++cnt;
		m /= 10;
	}

	for (int i = 1; i <= cnt; ++i)
	{
		a[i] = n % 10;
		if (n) n /= 10;
	}

	sort(a + 1, a + cnt + 1);
}

void Perm(int k)
{
	if (k > cnt)
	{
		Suma();
		return;
	}

	for (int i = 1; i <= cnt; ++i)
	{
		x[k] = i;

		if (!pus[i])
		{
			pus[i] = true;
			Perm(k + 1);
			pus[i] = false;
		}
	}
}

void Suma()
{
	int nr = 0;
	for (int i = 1; i <= cnt; ++i)
		nr = nr * 10 + a[x[i]];

	S += nr;
}