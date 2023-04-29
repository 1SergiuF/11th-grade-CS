#include <fstream>
#include <vector>
using namespace std;

ifstream fin("frunze.in");
ofstream fout("frunze.out");

#define N 101
int t[N];
int k;
vector<int> frunze;

bool Gasit(int nod);
int main()
{
    int root = int();
    fin >> k;

    for (int i = 1; i <= k; ++i)
    {
        fin >> t[i];
        if (t[i] == 0)
            root = i;
    }

    fout << root << '\n';
    for (int i = 1; i <= k; ++i)
    {
        if (!Gasit(i))
            frunze.push_back(i);
    }

    fout << frunze.size() << '\n';
    for (auto const& val : frunze)
        fout << val << ' ';
}

bool Gasit(int nod)
{
    for (int i = 1; i <= k; ++i)
        if (nod == t[i])
            return true;

    return false;
}