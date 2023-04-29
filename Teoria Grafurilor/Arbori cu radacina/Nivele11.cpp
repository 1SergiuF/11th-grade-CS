#include <fstream>
#include <queue>
#include <set>
#include <tuple>
using namespace std;
using PI = pair<int, int>;

ifstream fin("nivele11.in");
ofstream fout("nivele11.out");

const int N = 101;
int t[N];
int n;
int root;

void Bfs(int nod);
int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> t[i];
        if (t[i] == 0)
            root = i;
    }

    Bfs(root);

    return 0;
}

void Bfs(int nod)
{
    queue<PI> Q;
    set<int> s;

    Q.push({nod, 1});
    int niv;
    int niv_c = 1;

    fout << nod << '\n';
    while (!Q.empty())
    {
        tie(nod, niv) = Q.front();
        Q.pop();

        if (niv != niv_c)
        {
            for (int const& y : s)
                fout << y << ' ';
            fout << '\n';
            niv_c = niv;
            s.clear();
        }

        for (int f = 1; f <= n; ++f)
            if (t[f] == nod)
            {
                Q.push({f, niv + 1});
                s.insert(f);
            }
    }
}