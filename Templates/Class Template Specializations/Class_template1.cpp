// Class Template Specialization

#include <iostream>

template <
    typename T1,
    typename T2,
    typename T3

> class Container {
public:
    Container() : t1 {T1()}, t2 {T2()}, t3 {T3()}
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

    Container(T1 const& t1, T2 const& t2, T3 const& t3) :
        t1 {t1}, t2 {t2}, t3 {t3}
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

private:
    T1 t1;
    T2 t2;
    T3 t3;
};

int main()
{
    Container<int, float, double> c1;
    Container<char, int, std::string> c2 {'S', 17, "Sergiu"};
}