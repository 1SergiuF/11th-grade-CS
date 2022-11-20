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
    C a;
    cout << "prima instructiune\n";

    C(); // r-value (obiect TEMPORAR, anonim)
    
    cout << "ultima instructiune\n";
}