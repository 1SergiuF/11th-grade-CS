#include <iostream>
using namespace std;

int c1, c2;
int x[50];

void Back(int k);
void ScrieSol();
bool Ok(int k);

int main()
{
	cin >> c1 >> c2;
	if (c1 > c2) swap(c1, c2);
	Back(1);
}

void Back(int k)
{
	if (k > c1 + c2)
	{
		ScrieSol();
		return;
	}

	for (int i = -1; i <= 1; i += 2)
	{
		x[k] = i;
		if (Ok(k))
			Back(k + 1);
	}
}

void ScrieSol()
{
    for (int i = 1; i <= c1 + c2; ++i)
    	if (x[i] == -1) cout << c1;
    else cout << c2;

    cout << '\n';
}

bool Ok(int k)
{
	int cnt1 = 0, cnt2 = 0;

	for (int i = 1; i <= k; ++i)
		if (x[i] == -1) ++cnt1;
		else ++cnt2;

	if (cnt1 <= c2 && cnt2 <= c1)
		return true;

	return false;
}