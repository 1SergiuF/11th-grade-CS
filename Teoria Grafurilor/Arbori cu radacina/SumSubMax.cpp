#include <fstream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

ifstream fin("sumsubmax.in");
ofstream fout("sumsubmax.out");

const int N = 101;
int t[N];
int val[N];
int sum, sum_max = -1001;
int n;

void Dfs(int nod);

typedef pair<int, int> PI;
int main()
{
    priority_queue<PI, vector<PI>, std::greater<PI>> pq;
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> t[i];

    for (int i = 1; i <= n; ++i)
        fin >> val[i];

    for (int i = 1; i <= n; ++i)
    {
        sum = 0;
        Dfs(i);
        sum_max = max(sum_max, sum);
        pq.emplace(sum, i);
    }

    while (!pq.empty())
    {
        if (pq.top().first == sum_max)
            fout << pq.top().second << ' ';
        pq.pop();
    }

    return 0;  
}

void Dfs(int nod)
{
    sum += val[nod];
    for (int f = 1; f <= n; ++f)
        if (t[f] == nod)
            Dfs(f);
}