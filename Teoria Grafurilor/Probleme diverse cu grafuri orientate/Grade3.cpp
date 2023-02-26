#include <iostream>
#include <vector>
using namespace std;

const int N = 101;
bool a[N][N];
int n, m;
int gi[N];
int ge[N];
vector<int> noduri;

void CitesteGraf();

int main()
{
    CitesteGraf();

    for (int i = 1; i <= n; ++i)
        if (ge[i] < gi[i])
            noduri.push_back(i);

    cout << noduri.size() << '\n';
    for (auto const& nod : noduri)
        cout << nod << ' ';

    return 0;
}

void CitesteGraf()
{
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; ++i)
    {
        cin >> x >> y;
        a[x][y] = true;
        ge[x]++;
        gi[y]++;
    }
}