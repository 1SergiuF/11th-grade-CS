/*
    Left Values, Right Values
    l-value, r-value
    lvalue, rvalue

    Definitii:
    Un l-value este o entitate care poate fi
    operandul din stanga al unei atribuiri.

    Un r-value este o entitate care poate sta NUMAI
    in dreapta unei atribuiri

    L-values: - variabile simple
              - obiecte
              - referinte

    R-values: - constante (10, 2.3, 'H', "Ion", obiecte definite cu const)
              - obiecte temporare
*/

#include <iostream>
using namespace std;

struct C {
    C()
    {
        cout << "C()\n";
    }

    ~C()
    {
        cout << "~C()\n";
    }
};

int main()
{
    cout << "prima instructiune\n";
    C c1;  // c1 = l-value
    C c2;  // c2 = l-value

    c1 = c2;
    c2 = c1;

    cout << "ultima instructiune\n";

}   // c1 si c2 sunt vizibile pana aici