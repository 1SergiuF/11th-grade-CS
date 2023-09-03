#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    int n, k;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (log2(n) < k) cout << n + 1 << '\n';
        else cout << (int)pow(2, k) << '\n';
    }

    return 0;
}