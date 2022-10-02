#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
    T aux = a;
    a = b;
    b = aux;
}

int main()
{
    int a = 7, b = 2;
    swap(a, b);
    std::cout << a << ' ' << b << '\n';

    std::string x = "Ana", y = "Mara";
    ::swap(x, y);
    std::cout << x << ' ' << y;
}