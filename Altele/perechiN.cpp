#include <iostream>
using namespace std;

int main()
{
	int n, x = 0, y = 1;
	int m;

	cin >> n;
	(n % 2 == 0) ? m = n / 2 : m = (n - 1) / 2;

	while (m--)
	{
		++x;
		y = n - x;

		cout << x << ' ' << y << '\n';
	}

	return 0;
}