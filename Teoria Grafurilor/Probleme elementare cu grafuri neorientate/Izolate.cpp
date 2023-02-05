#include <fstream>
#include <stack>
using namespace std;

ifstream fin("izolate.in");
ofstream fout("izolate.out");

#define DIM 101
int n;
int g[DIM];
bool a[DIM][DIM];

void CitesteDate();
void AfiseazaMat();

stack<int> stk;
int main()
{
	CitesteDate();
	AfiseazaMat();

	return 0;
}

void CitesteDate()
{
	fin >> n;
	int x, y;
	while (fin >> x >> y)
	{
		if (a[x][y] == false)
		{
			a[x][y] = a[y][x] = true;
			g[x]++;
			g[y]++;
		}
	}
}

void AfiseazaMat()
{
	for (int i = n; i >= 1; --i)
		if (!g[i]) stk.push(i);

    fout << stk.size() << ' ';
    while (!stk.empty())
    {
        fout << stk.top() << ' ';
        stk.pop();
    }
}