#include <iostream>
using namespace std;

int x[30], n;
int cnt;
int nr_0, nr_1;

void Back(int k);
void ScrieSol();
bool Ok(int k);

int main()
{
	cin >> n;
	while (n)
	{
		if (n % 2)
			++nr_1;

		++cnt;
		n /= 2;
	}

	nr_0 = cnt - nr_1;

	Back(1);
}

void Back(int k)
{
	if (k > cnt)
	{
		ScrieSol();
		return;
	}

	for (int i = 0; i <= 1; ++i)
	{
		x[k] = i;
		if (Ok(k))
			Back(k + 1);
	}
}

void ScrieSol()
{
	for (int i = 1; i <= cnt; ++i)
		cout << x[i];
	cout << '\n';
}

bool Ok(int k)
{
	int cnt1 = 0, cnt2 = 0;

	for (int i = 1; i <= k; ++i)
		if (x[i] == 0) ++cnt1;
		else ++cnt2;

	if (cnt1 <= nr_0 && cnt2 <= nr_1)
		return true;

	return false;
}