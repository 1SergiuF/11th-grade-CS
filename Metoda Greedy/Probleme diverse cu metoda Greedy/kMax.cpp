#include <iostream>
#include <algorithm>
using namespace std;

const int Dim = 1001;
int n, k;
int a[Dim];
int sum;

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
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    cin >> k;
    sort(a + 1, a + n + 1);
}

void Greedy()
{
    int cnt = 1;
    while (k)
    {
        a[cnt] *= -1;
        --k;
    }

    for (int i = 1; i <= n; ++i)
        sum += a[i];

    cout << sum;
}