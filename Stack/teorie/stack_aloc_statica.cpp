/*
   STIVA = o structura de date liniara,
   care suporta operatiile:
   1. push(val)  - adauga val pe varful stivei
   2. pop()      - sterge elementul din varful stivei


   Stiva impplementeaza mecanismul LIFO
   (Last In First Out)
*/

#include <iostream>
using namespace std;

const int N = 1001;
int stk[N];  // suportul pentru stiva
int k;       // pozitia elementului din varful stivei


// Operatii
void push(int val);
void pop();

// Functii utilitare
bool empty();
int top();

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    while (!empty())
    {
        cout << top() << '\n'; // afisez elementul din varful stivei
        pop();
    }
}

void push(int val)
{
    stk[++k] = val;
}

void pop()
{
    --k;
}

bool empty()
{
    return k <= 0;
}

int top()
{
    return stk[k];
}