#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;

ifstream fin("biminprim.in");
ofstream fout("biminprim.out");

struct Nod {
    int val;
    Nod *fs, *fd;
};

Nod* CitPreOrd();
void PreOrdine(Nod* ptr);
bool Prim(int x);
void DezalocaArbore(Nod* ptr);

Nod* root;
int v_min = INT_MAX;

int main()
{
    root = CitPreOrd();

    PreOrdine(root->fs);

    if (v_min == INT_MAX)
        fout << "-1 ";
    else
        fout << v_min << ' ';

    v_min = INT_MAX;
    PreOrdine(root->fd);
    
    if (v_min == INT_MAX)
        fout << "-1";
    else
        fout << v_min;

    DezalocaArbore(root);
    return 0;
}

int val;
Nod* CitPreOrd()
{
    fin >> val;
    if (!val) return nullptr;

    Nod* ptr = new Nod;
    ptr->val = val;
    ptr->fs = CitPreOrd();
    ptr->fd = CitPreOrd();

    return ptr;
}

void PreOrdine(Nod* ptr)
{
    if (!ptr) return;

    if (Prim(ptr->val))
        v_min = min(v_min, ptr->val);

    PreOrdine(ptr->fs);
    PreOrdine(ptr->fd);
}

void DezalocaArbore(Nod* ptr)
{
    if (!ptr) return;

    DezalocaArbore(ptr->fs);
    DezalocaArbore(ptr->fd);

    delete ptr;
}

bool Prim(int x)
{
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;

    return true;
}