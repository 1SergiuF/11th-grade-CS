#include <iostream>
#include "vector.h"

void Print1(Vector<int> const& v);
void Print2(Vector<int>& v);
void Print3(Vector<int>& v);
void Print4(Vector<int>& v);
template<typename T> void Print5(Vector<T>& v);
template<typename Type> void Print6(Type& v);

int main()
{
	Vector<int> a{ 10, 20, 30, 40, 50 };
	Print1(a);
    Print2(a);
    Print3(a);
    Print4(a);

    Vector<std::string> b {"Sergiu", "Paul", "Emi"};
    Print5(b);
    Print6(b);

	return 0;
}

void Print1(Vector<int> const& v)
{
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << ' ';
    std::cout << '\n';
}

void Print2(Vector<int>& v)
{
    for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
}

void Print3(Vector<int>& v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
}

void Print4(Vector<int>& v)
{
    for (auto x : v)
        std::cout << x << ' ';
    std::cout << '\n';
}

template<typename T> void Print5(Vector<T>& v)
{
    for (T const& x : v)
        std::cout << x << ' ';
    std::cout << '\n';
}

template<typename Type> void Print6(Type& v)
{
    for (auto x : v)
        std::cout << x << ' ';
    std::cout << '\n';
}