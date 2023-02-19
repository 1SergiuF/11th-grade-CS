#include <fstream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

ifstream fin("bipartit.in");
ofstream fout("bipartit.out");

int n, m;
int k;
int cnt;

vector<int> A;
queue<pair<int, int>> q;

void CitesteGraf();
bool VerifExtremitati(vector<int>& v, int x, int y);

int main()
{
    CitesteGraf();

    while (!q.empty())
    {
        auto [x, y] = q.front();
        if (VerifExtremitati(A, x, y))
            ++cnt;

        q.pop();
    }

    if (cnt == m) fout << "DA";
    else fout << "NU";

    return 0;
}

bool VerifExtremitati(vector<int>& v, int x, int y)
{
    for (auto const& val : v)
        if (x == val || y == val)
            return true;

    return false;
}

void CitesteGraf()
{
    fin >> n >> m;
    for (int i = 1, x, y; i <= m; ++i)
    {
        fin >> x >> y;
        q.emplace(x, y);
    }

    fin >> k;
    for (int i = 1, z; i <= k; ++i)
    {
        fin >> z;
        A.push_back(z);
    }
}