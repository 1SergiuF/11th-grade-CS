#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Magazin {
	int pret, cantitate;
	
	friend istream& operator >> (istream& is, Magazin& mg)
	{
		return is >> mg.pret >> mg.cantitate;
	}
	
	bool operator < (Magazin const& mg) const noexcept
	{
		return pret > mg.pret;
	}
};

const int N = 101;
int n, m;
Magazin c[N];

void CitesteDate();
void Greedy();

int main()
{
	CitesteDate();
	Greedy();
	
	return 0;
}

void CitesteDate()
{
	cin >> n >> m;
	
	for (int i = 1; i <= m; ++i)
		cin >> c[i];
		
	sort(c + 1, c + m + 1);
}

void Greedy()
{
	int S = 0, cnt = 0;
	int k = n;
	
	for (int i = m; i >= 1; --i)
	{

		if (n < c[i].cantitate)
		{
			cnt += n;
			S += n * c[i].pret;
			n = 0;
		}

		else
		{
			cnt += c[i].cantitate;
			n -= c[i].cantitate;
			S += c[i].cantitate * c[i].pret;
		}
	}

	string rez = (cnt == k) ? to_string(S) : "imposibil";
	cout << rez;
}
