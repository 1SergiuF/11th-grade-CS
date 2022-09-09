/*
    Class Template (Sablon de Clasa)
*/

#include <iostream>
#include <vector>
#include <set>

template<
    class T1,
    class T2
> class Container {
public:
    Container() : t1 {T1()}, t2 {T2()} {}

    Container(T1 const& t1, T2 const& t2) : t1 {t1}, t2 {t2} {}

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
    /*
       Compile-time, pe baza sablonului de clasa,
       compilatorul genereaza (INSTANTIAZA)
       urmatoarele clase concrete:
        Container<int, char>,
        Container<int, float>,
        Container<vector<int>, set<char>>
    */

   Container<int, char> c1;
   Container<int, float> c2 {100, 23.45};
   Container<std::vector<int>, std::set<char>> c3;
}