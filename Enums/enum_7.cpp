/*
  Enumerari
  CU ajutorul cuvintelor cheie (keywords) :
  class, struct, union, enum se creaza in C++
  noi tipuri de date

*/

#include <iostream>

namespace Qt {

    enum class Color {
        // Enumeratorii NU mai sunt injectati in afara enumerarii       
        red = 12763,
        blue = 328474,
        yellow = 32456,
        white = 3455
    };
}

// :: Scope Resolution Operator (operator de rezolvare a domeniului)
int main()
{
    // Obligatoriu sa fie trecut si numele enumerarii
    Qt::Color c = Qt::Color::red;

    if (c == Qt::Color::red)
        std::cout << "rosu";
}