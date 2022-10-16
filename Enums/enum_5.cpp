/*
  Enumerari
  CU ajutorul cuvintelor cheie (keywords) :
  class, struct, union, enum se creaza in C++
  noi tipuri de date

*/

#include <iostream>

enum Color {
    red = 12763,
    blue = 328474,
    yellow = 32456,
    white = 3455
};

/*
   Enumeratorii sunt "injectati" in afar enumerarii
*/

// :: Scope Resolution Operator (operator de rezolvare a domeniului)
int main()
{
    std::cout << Color::red << ' ' << red << '\n';
    std::cout << Color::blue << ' ' << blue;
}