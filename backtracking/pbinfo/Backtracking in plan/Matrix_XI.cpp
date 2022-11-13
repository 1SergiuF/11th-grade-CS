#include <iostream>
using namespace std;

const int Dim = 11,
		  di[] = {-1, 0, 1, 0},
		  dj[] = {0, 1, 0, -1};

int n, m, x, y;
int a[Dim][Dim];
int nrsol, poz;

void CitesteMatrix();
bool Ok(int i, int j);
void Matrix(int i, int j, int k);

int main()
{
	CitesteMatrix();
	Matrix(x, y, 1);

	if (!nrsol) cout << "Mr. Anderson wins!";
	else cout << nrsol;

	return 0;
}

void CitesteMatrix()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j], poz += a[i][j];

	cin >> x >> y;
}

bool Ok(int i, int j)
{
	if (i < 1 || i > n || j < 1 || j > m)
		return false;

	if (!a[i][j])
		return false;

	return true;
}

#define iv (i + di[d])
#define jv (j + dj[d])

void Matrix(int i, int j, int k)
{
	if (!Ok(i, j)) return;
	--a[i][j];

	if (k == poz)
		++nrsol;

	for (int d = 0; d < 4; ++d)
		Matrix(iv, jv, k + 1);

	++a[i][j];
}
