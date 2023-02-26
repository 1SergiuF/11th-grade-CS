#include <iostream>
#include <vector>
#include <functional>
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
        if ((ge[i] && gi[i]) && (ge[i] % gi[i] == 0 || gi[i] % ge[i] == 0))
            noduri.push_back(i);

    
    std::function<void()> f_display = [&]() {
        for (auto const& nod : noduri)
            cout << nod << ' ';
    };

    if (!noduri.size()) cout << "NU EXISTA";
    else f_display();
    
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