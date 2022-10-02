#include <iostream>
using namespace std;

int a, b, p, cnt;
int x[20], sol[20];
bool s[20];

void CitesteDate();
void Aranj(int k);
void ScrieSol();

int main()
{
	CitesteDate();
	Aranj(1);
	return 0;
}

void CitesteDate()
{
	cin >> a >> b >> p;
	for (int i = a; i <= b; ++i)
		sol[++cnt] = i;
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
	for (int i = 1; i <= p; ++i)
		cout << sol[x[i]] << ' ';
	cout << '\n';
}