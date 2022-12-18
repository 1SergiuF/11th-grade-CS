#include <algorithm>
#include <iostream>
using namespace std;

const int K = 52, MOD = 5000000, MaxVal = 100048, Dim = 10001;

int aib[K][Dim];
int Val = 0;
int v[Dim];
int map[MaxVal];
int a[Dim];

int Query(int k, int x)
{
    int sum = 0;
    for (int i = x; i; i -= (i & i))
    {
        sum += aib[k][i];
        if (sum >= MOD)
            sum -= MOD;
    }

    return sum;
}

void Update(int k, int x, int v)
{
    for (int i = x; i <= Val; i += (i & -i))
    {
        aib[k][i] += v;
        if (aib[k][i] >= MOD)
            aib[k][i] -= MOD;
    }
}

int main()
{
    int K, N;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
        v[i] = a[i];
    }

    sort(a, a + N);

    map[a[0]] = ++Val;

    for (int i = 1; i < N; ++i)
        if (a[i] == a[i - 1])
            map[a[i]] = Val;
        else
            map[a[i]] = ++Val;

    //  O(N * K * log(N))
    for (int i = 0; i < N; ++i)
    {
        int x = map[v[i]];

        Update(1, x, 1);

        for (int k = 2; k <= K; ++k)
        {
            int cnt = Query(k - 1, x - 1);
            if (cnt)
                Update(k, x, cnt);
        }
    }

    cout << Query(K, Val);
    return 0;
}