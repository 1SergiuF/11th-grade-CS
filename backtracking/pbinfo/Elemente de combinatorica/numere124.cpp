#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, p, cnt;
int x[20], ar[20];
bool s[20];

void Aranj(int k);
void ScrieSol();

int main()
{
	cin >> n >> p;

    while (n)
    {
        ar[++cnt] = n % 10;
        n /= 10;
    }

    sort(ar + 1, ar + cnt + 1);
	Aranj(1);

	return 0;
}

void Aranj(int k)
{
	if (k > p)
	{
		ScrieSol();
		return;
	}

	for (int i = 1; i <= cnt; ++i)
	{
		x[k] = i;
		if (!s[i])
		{
			s[i] = true;
			Aranj(k + 1);
			s[i] = false;
		}
	}
}

void ScrieSol()
{
	if (!ar[x[1]]) return;

	for (int i = 1; i <= p; ++i)
		cout << ar[x[i]];
	cout << '\n';
}