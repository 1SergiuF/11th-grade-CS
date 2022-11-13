/*
    Class Template (Sablon de Clasa)
*/

#include <iostream>

template <typename T>
class Container {
public:
    Container();
    Container(T const& t);
    void PrintInfo() const noexcept;

    template <class U>
    U const& Suma(U const& a, U const& b);

private:
    T t;
};

template <class T>
template <class U>
U const& Container<T>::Suma(U const& a, U const& b)
{
    return a + b;
}

template <class T>
Container<T>::Container() : t {T()}
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
}

template <class T>
Container<T>::Container(T const& t) : t {t}
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
}

template <class T>
void Container<T>::PrintInfo() const noexcept
{
    std::cout << t << ' ';
}

int main()
{
    int x = int(); // 0
    
    // Argumentul template "int" este explicit
    Container<int> c1 {x};
    Container<char> c2;
}