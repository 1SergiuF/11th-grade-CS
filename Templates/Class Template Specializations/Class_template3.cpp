// Class Template Specialization

#include <iostream>

// Primary Template
template <
    typename T1,
    typename T2,
    typename T3

> class Container {
public:
    void DoSomething()
    {
        std::cout << "Sablonul general\n";
    }
};

// Partial Specialization

template <
    typename T1,
    typename T2

> class Container<T1, T2, int> {    // T1, T2, int - Argumente template explicite
public:
    void DoSomething()
    {
        std::cout << "Specializare partiala 1\n";
    }
};

template <typename U>
class Container<U, U, int> {
public:
    void DoSomething()
    {
        std::cout << "Specializare partiala 2\n";
    }
};

// Full Specialization
template<>
class Container<float, float, int> {
public:
    void DoSomething()
    {
        std::cout << "Full Specialization\n";
    }
};

int main()
{
	/*
		Polimorfism Static 
		Compile-time Polymorphism
		(Selectia codului ca va trebui executat
		se face in timpul compilarii)
	*/

    Container<char, double, std::string> c1;
    c1.DoSomething();

    Container<char, double, int> c2;
    c2.DoSomething();

    Container<char, char, int> c3;
    c3.DoSomething();

    Container<float, float, int> c4;
    c4.DoSomething();
}