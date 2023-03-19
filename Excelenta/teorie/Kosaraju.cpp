/* Det Componentelor tare-conexe.
 * Algoritmul lui Kosaraju
 * 
 * Complexitate: 
 * 	O(2 * m) adica O(m)  - timp de executare
 *  O(2 * m) adica O(m)  - ca spatiu de memorie ocupat
 */ 

#include <fstream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

ifstream fin("kosaraju.in");
ofstream fout("kosaraju.out");
int n, m;
VVI G, GT;  // graful / graful transpus
VB v;
VVI ctc;    // retine pe fiecare linie cate o comp tare-conexa
VI c;       // componenta tare-conexa curenta
stack<int> stk;     // retine nodurile in ordinea timpilor de terminare la parcurgerea Dfs

void CitesteGraf();
void Df(int x);
void Dft(int x);    // pe graful transpus
void Kosaraju();
void ScrieCTC();

int main()
{
    CitesteGraf();
    Kosaraju();
    ScrieCTC();
    
    return 0;
}

void Kosaraju() // O(2 * m) = O(m)
{
    for (int nod = 1; nod <= n; ++nod)  // O(m)
        if (!v[nod])
            Df(nod);

    v = VB(n + 1, false);
    while (!stk.empty()) // O(m)
    {
        int x = stk.top();
        stk.pop();
        if (v[x]) continue;

        c.clear();
        Dft(x);
        ctc.push_back(c);
    }
}

void Dft(int x) // O(m)
{
    v[x] = true;
    c.push_back(x);
    for (int const& y : GT[x])
        if (!v[y])
            Dft(y);
}

void Df(int x)  // O(m)
{
    v[x] = true;
    for (int const& y : G[x])
        if (!v[y])
            Df(y);

    stk.push(x);
}

void ScrieCTC()
{
    fout << ctc.size() << '\n';
    for (VI const& cc : ctc)
    {
        for (int const& x : cc)
            fout << x << ' ';
        fout << '\n';
    }
}

void CitesteGraf()
{
    fin >> n >> m;
    G = GT = VVI(n + 1);
    v = VB(n + 1);
    int x, y;
    while (m--)
    {
        fin >> x >> y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }
}