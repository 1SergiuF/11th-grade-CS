#include <iostream>
#include <algorithm>
using namespace std;

int n, S;
int a[1001];
int cnt;

void ReadData();
void Greedy();

int main()
{
    ReadData();
    Greedy();

    return 0;
}

void ReadData()
{
    cin >> n >> S;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
}

void Greedy()
{
    long long s = 0;
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; ++i, ++cnt)
    {
        s += a[i];
        if(s > S)
        {
            s -= a[i];
            break;
        }
    }

    if(cnt == n)
        cout << cnt << ' ' << 0;
    else
        cout << cnt << ' ' << a[cnt + 1] - (S - s);
}