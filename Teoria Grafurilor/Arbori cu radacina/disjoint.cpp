#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

vector<int> t, card;
int n, m;

void Union(int x, int y);
int Find(int x);
void Init();

int main()
{
    cin >> n >> m;
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    t = card = vector<int>(n + 1);
    Init();

    int op, x, y;
    for (int i = 1; i <= m; ++i)
    {
        cin >> op >> x >> y;
        if (op == 1)
            Union(t[x], t[y]);

        else if (op == 2)
        {
            int r1 = Find(x);
            int r2 = Find(y);
            if (r1 == r2)
				cout << "DA" << '\n';
			else
				cout << "NU" << '\n';
        }
    }

    return 0;
}

void Union(int x, int y)
{
    if (card[x] < card[y])
        swap(x, y);

    t[y] = x;
    card[x] += card[y];
}

int Find(int x)
{
    if (t[x] == x) return x;
    return t[x] = Find(t[x]);
}

void Init()
{
    for (int i = 1; i <= n; ++i)
    {
        t[i] = i;
        card[i] = 1;
    }
}