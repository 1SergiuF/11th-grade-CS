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
    Luni = 55, Marti = 68, Miercuri = 123, Joi = 256,
    Vineri = 1337, Sambata = 1890, Duminica = 109
};

int main()
{
    std::cout << Saptamana::Luni << ' ' << Saptamana::Marti << ' '
              << Saptamana::Miercuri << ' ' << Saptamana::Joi << ' '
              << Saptamana::Vineri << ' ' << Saptamana::Sambata << ' '
              << Saptamana::Duminica << '\n';
}