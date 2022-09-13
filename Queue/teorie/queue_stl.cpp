/*
   COADA = o structura de date liniara,
   care suporta operatiile:
   1. push(val)  - adauga un element la sfarsitul cozii
   2. pop()      - sterge primul element din coada


   Coada implementeaza mecanismul FIFO
   (First In First Out)
*/

#include <iostream>
#include <queue>

int main()
{
    std::queue<int> Q;

    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);

    while (!Q.empty())
    {
        std::cout << Q.front() << ' '; // afisez elem in ordinea din coada
        Q.pop();
    }
}