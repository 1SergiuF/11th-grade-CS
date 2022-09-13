/*
   COADA = o structura de date liniara,
   care suporta operatiile:
   1. push(val)  - adauga un element la sfarsitul cozii
   2. pop()      - sterge primul element din coada


   Coada implementeaza mecanismul FIFO
   (First In First Out)
*/

#include <iostream>
using namespace std;

const int N = 1001;
int Q[N]; // suportul pentru coada
int p = 1, u; // pozitia primului si a ultimului element din coada


// operatii
void push(int val);
void pop();

// Functii utilitare
bool empty();
int front();

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    while (!empty())
    {
        cout << front() << ' '; // afisez elem in ordinea din coada
        pop();
    }
}

void push(int val)
{
    Q[++u] = val;
}

void pop()
{
    ++p;
}

bool empty()
{
    return p > u;
}

int front()
{
    return Q[p];
}