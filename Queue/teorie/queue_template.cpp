/*
   COADA = o structura de date liniara,
   care suporta operatiile:
   1. push(val)  - adauga un element la sfarsitul cozii
   2. pop()      - sterge primul element din coada


   Coada implementeaza mecanismul FIFO
   (First In First Out)
*/

#include <iostream>
#include <deque>

// clasa adaptoare
template<
    class T,
    class Container = std::deque<T>
> class queue {
public:

    // operatii
    void push(T const& value)
    {
        c.push_back(value);
    }

    void pop()
    {
        c.pop_front();
    }

    T& front()
    {
        return c.front();
    }

    T& back()
    {
        return c.back();
    }

    bool empty() const noexcept
    {
        return c.empty();
    }

    size_t size() const noexcept
    {
        return c.size();
    }

private:
    Container c;
};

int main()
{
    ::queue<int> Q;
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