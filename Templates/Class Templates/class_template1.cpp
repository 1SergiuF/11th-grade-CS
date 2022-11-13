/*
    Class Template (Sablon de Clasa)
*/

#include <iostream>
using namespace std;

template <typename T>
class Container {
public:
    Container(T const& t) : t {t} {}

private:
    T t;
};

int main()
{
    int x = 100;
    // Argumentul template "int" este explicit
    Container<int> c {x};
    cout << x;
}