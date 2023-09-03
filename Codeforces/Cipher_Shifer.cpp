#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	int n;
	string s;
	string a;

	cin >> t;
	while (t--)
	{
		a = "";
		cin >> n;
		cin >> s;

		char c = s[0];
		for (size_t i = 1; i < s.size(); ++i)
			if (c == s[i])
			{
				cout << c;
				c = s[i + 1];
				i++;
			}

		cout << '\n';
	}

	return 0;
}