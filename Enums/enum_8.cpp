/*
  Enumerari
  CU ajutorul cuvintelor cheie (keywords) :
  class, struct, union, enum se creaza in C++
  noi tipuri de date

*/

#include <iostream>

namespace Qt {

    enum Color {      
        red = 12763,
        blue = 328474,
        yellow = 32456,
        white = 3455
    };
}

// :: Scope Resolution Operator (operator de rezolvare a domeniului)
int main()
{
    Qt::Color c = Qt::red;
    // O variabila de tip enum poate retine doar un singur enumerator

    if (c == Qt::red)
        std::cout << "rosu";
}