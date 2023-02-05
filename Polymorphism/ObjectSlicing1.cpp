/*
    OBJECT SLICING
    Felierea/fragmentarea obiectelor
*/

#include <iostream>

class A {
public:
    A()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

    ~A()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
};

class B : public A {
public:
    B()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

    ~B()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
};

int main()
{
    A *ptr = new B();

    // Object Slicing - se distruge numai partea de baza a obectului
    delete ptr;   // ~A() - Static Binding (early binding) - compile-time
}