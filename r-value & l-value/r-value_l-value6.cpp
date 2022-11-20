/*
    Left Value Reference    &
    Right Value Reference   &&

    &  - poate fi legat NUMAI la l-values
    && - poate fi legat NUMAI la r-values

    Right Value Reference(&&) s-a introdus
    pentru a se putea face un transfer de resurse
    de la un r-value catre un left-value
*/

#include <iostream>
using namespace std;

struct Int {
    Int(int n) : n {n}
    {
        cout << "Int(int)\n";
    }

    ~Int()
    {
        cout << "~Int()\n";
    }

    int n;
};

void F (const Int& a)
{
    cout << __PRETTY_FUNCTION__ << '\n';
}

void F (Int& a)  // & - Left Value Reference
{
    cout << __PRETTY_FUNCTION__ << '\n';
}

void F (Int&& a)  // && - Right Value Reference
{
    a.n = 10;
    cout << __PRETTY_FUNCTION__ << '\n';
}

int main()
{
    Int a {10}; // a = l-value
    F(a);

    F(Int(1000)); // Int(1000) - r-value
}