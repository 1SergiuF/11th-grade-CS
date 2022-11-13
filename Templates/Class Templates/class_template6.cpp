/*
  ARGUMENTE TEMPLATE IMPLICITE
*/

#include <iostream>

template<
    class T1 = float,
    class T2 = int
> class Container {
public:
    Container() : t1 {T1()}, t2 {T2()}
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

    Container(T1 const& t1, T2 const& t2) :
        t1 {t1}, t2 {t2}
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

    void PrintInfo() const noexcept
    {
        std::cout << t1 << ' ' << t2;
    }

private:
    T1 t1;
    T2 t2;
};

int main()
{
    Container<int, char> c1;
    Container<double> c2;
    Container<> c3;
}