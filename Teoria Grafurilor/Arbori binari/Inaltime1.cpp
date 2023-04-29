#include <fstream>
using namespace std;

ifstream fin("inaltime1.in");
ofstream fout("inaltime1.out");

struct Nod {
    int val;
    Nod *fs, *fd;
};

int val;
int niv_max;

Nod* CitPreOrd();
void Inaltime(Nod* ptr, int nm);
void DezalocaArbore(Nod* ptr);

int main()
{
    Nod* root = CitPreOrd();
    Inaltime(root, 1);

    fout << niv_max;

    DezalocaArbore(root);
    return 0;
}

Nod* CitPreOrd()
{
    fin >> val;
    if (val == 0) return nullptr;

    Nod* ptr = new Nod;
    ptr->val = val;
    ptr->fs = CitPreOrd();
    ptr->fd = CitPreOrd();

    return ptr;
}

void Inaltime(Nod* ptr, int nm)
{
    if (ptr == nullptr) return;

    niv_max = max(niv_max, nm);
    Inaltime(ptr->fs, nm + 1);
    Inaltime(ptr->fd, nm + 1);
}

void DezalocaArbore(Nod* ptr)
{
    if (ptr == nullptr) return;

    DezalocaArbore(ptr->fs);
    DezalocaArbore(ptr->fd);
    delete ptr;
}