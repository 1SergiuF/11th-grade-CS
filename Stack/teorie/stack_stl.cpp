/*
   STIVA = o structura de date liniara,
   care suporta operatiile:
   1. push(val)  - adauga val pe varful stivei
   2. pop()      - sterge elementul din varful stivei


   Stiva impplementeaza mecanismul LIFO
   (Last In First Out)
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>

int main()
{
    std::stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    while (!s1.empty())
    {
        std::cout << s1.top() << '\n'; // afisez elementul din varful stivei
        s1.pop();
    }

    std::stack<std::string, std::vector<std::string>> s2;
    s2.push("Ion");
    s2.push("Vasile");
    s2.push("Ana");
    s2.push("George");

    while (!s2.empty())
    {
        std::cout << s2.top() << '\n'; // afisez elementul din varful stivei
        s2.pop();
    }
}