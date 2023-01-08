/**
    Numerele lui Catalan
    Probl:
    1. Sa se det. nr de expresii corect parantezate,
    daca se dau n perechi de partanteze

    2. Se dau n perechi de segmente / \
    Sa se det. nr de formatiuni muntoase care se po obtine,
    a.i. muntele sa inceapa si sa se termine la nivelul solului.

    3. Numarul de drumuri de lungime minima pe laturile unui grid,
       drumuri care nu coboara sub diagonala principala

    n = 3
      /\
     /  \    /\        /\            /\/\
    /    \, /  \/\, /\/  \, /\/\/\, /    \
    ((())), (())(), ()(()), ()()(), (()())
    Raspuns: c[n]

    3.

*/

#include <iostream>
using namespace std;

const int Dim = 1000;
int main()
{
    int n;
    cin >> n;

    int c[Dim] = {0}; /// c[i] = nr de expr. corect parantezate avand i perechi

    c[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            c[i] += c[j] * c[i - j - 1];

    cout << c[n];
}
