#include <iostream>
using namespace std;

const int N = 31;
int trepte[N];
int n;

int main()
{
    cin >> n;
    trepte[0] = 0;
    trepte[1] = 1;
    trepte[2] = 2;

    int nr = 1;
    for (int i = 3; i <= n; ++i)
    {
        trepte[i] = trepte[i - 1] + nr;
        nr = trepte[i] - nr;
    }

    cout << trepte[n];
    
    return 0;
}