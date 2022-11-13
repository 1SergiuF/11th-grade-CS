/*
    Class Template (Sablon de Clasa)
*/

#include <iostream>

template <typename T>
class Container {
public:
    Container() : t {T()}
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

    Container(T const& t) : t {t}
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

    void PrintInfo() const noexcept
    {
        std::cout << t << ' ';
    }

private:
    T t;
};

int main()
{
    int x = int(); // 0
    
    // Argumentul template "int" este explicit
    Container<int> c1 {x};
    Container<char> c2;
}