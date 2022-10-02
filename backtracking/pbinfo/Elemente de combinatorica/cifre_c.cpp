#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int n, p, cnt;
int x[20], ar[20];

void Comb(int k);
void PushToQ();

priority_queue<int> Q;
int main()
{
    cin >> n >> p;

    while (n)
    {
        ar[++cnt] = n % 10;
        n /= 10;
    }

    sort(ar + 1, ar + cnt + 1);
    Comb(1);

    while (!Q.empty())
    {
        cout << Q.top() << '\n';
        Q.pop();
    }

    return 0;
}

void Comb(int k)
{
    if (k > p)
    {
        PushToQ();
        return;
    }

    for (int i = x[k - 1] + 1; i <= cnt - p + k; ++i)
    {
        x[k] = i;
        Comb(k + 1);
    }
}

void PushToQ()
{
    if (ar[x[1]] == 0) return;
    int g = 0;
    int m = p;
    for (int i = 1; i <= p; ++i)
    {
        g = g + (ar[x[i]] * pow(10, m - 1));
        m -= 1;
    }

    Q.push(g);
}