/*
  Enumerari
  CU ajutorul cuvintelor cheie (keywords) :
  class, struct, union, enum se creaza in C++
  noi tipuri de date

*/

#include <iostream>
using namespace std;

enum Saptamana {
    // Membrii unei enumerari se numesc enumeratori
    Luni, Marti, Miercuri = 123, Joi,
    Vineri, Sambata, Duminica
};

int main()
{
    std::cout << Saptamana::Luni << ' ' << Saptamana::Marti << ' '
              << Saptamana::Miercuri << ' ' << Saptamana::Joi << ' '
              << Saptamana::Vineri << ' ' << Saptamana::Sambata << ' '
              << Saptamana::Duminica << '\n';   // 0 1 123 124 125 126 127
}