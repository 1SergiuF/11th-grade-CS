#include <fstream>
#include <vector>
using namespace std;

ifstream fin("knivel1.in");
ofstream fout("knivel1.out");

struct Nod {
    int val;
    Nod *fs, *fd;
};

int val;
int sum;
int cnt;
int k;
vector<int> niv;

Nod* CitPreOrd();
void SetNivele(Nod* ptr, int nv);
void DezalocaArbore(Nod* ptr);

int main()
{
    Nod* root = CitPreOrd();
    fin >> k;
    niv = vector<int>(cnt + 1);
    SetNivele(root, 0);

    fout << niv[k];
    DezalocaArbore(root);
    return 0;
}

void SetNivele(Nod* ptr, int nv)
{
    if (!ptr) return;

    niv[nv] += ptr->val;
    SetNivele(ptr->fs, nv + 1);
    SetNivele(ptr->fd, nv + 1);
}

Nod* CitPreOrd()
{
    fin >> val;
    ++cnt;
    if (!val) return nullptr;

    Nod* ptr = new Nod;
    ptr->val = val;
    ptr->fs = CitPreOrd();
    ptr->fd = CitPreOrd();

    return ptr;
}

void DezalocaArbore(Nod* ptr)
{
    if (!ptr) return;

    DezalocaArbore(ptr->fs);
    DezalocaArbore(ptr->fd);
    delete ptr;
}