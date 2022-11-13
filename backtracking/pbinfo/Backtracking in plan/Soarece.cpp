#include <fstream>
#include <iomanip>
using namespace std;

ifstream fin("soarece.in");
ofstream fout("soarece.out");

#define iv (i + di[d])
#define jv (j + dj[d])

const int N = 20;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

int x[N][N];
int n, m;
int is, js, ip, jp;
int nrsol;

void CitesteLabirint();
bool Ok(int i, int j);
void Labirint(int i, int j, int k);

int main()
{
	CitesteLabirint();
	Labirint(ip, jp, 1);

	fout << nrsol;

	return 0;
}

void CitesteLabirint()
{
	fin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			fin >> x[i][j];

	fin >> ip >> jp >> is >> js;
}

bool Ok(int i, int j)
{
	if (i < 1 || i > n || j < 1 || j > m)
		return false;

	if (x[i][j] == 1)
		return false;

	if (x[i][j])
		return false;

	return true;
}

void Labirint(int i, int j, int k)
{
	if (!Ok(i, j)) return;
	x[i][j] = k;

	if (i == is && j == js)
		++nrsol;

	for (int d = 0; d < 4; ++d)
		Labirint(iv, jv, k + 1);

	x[i][j] = 0;
}