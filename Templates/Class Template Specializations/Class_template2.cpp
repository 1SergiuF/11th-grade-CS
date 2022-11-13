// Class Template Specialization

#include <iostream>

// Primary Template
template <
    typename T1,
    typename T2,
    typename T3

> class Container {
public:
    Container()
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
    Container()
    {
        std::cout << "Specializare partiala 1\n";
    }
};

template <typename U>
class Container<U, U, int> {
public:
    Container()
    {
        std::cout << "Specializare partiala 2\n";
    }
};

// Full Specialization
template<>
class Container<float, float, int> {
public:
    Container()
    {
        std::cout << "Full Specialization\n";
    }
};

int main()
{
    /*
		In situatia potrivirilor, 
		clasa cea mai specializata are prioritate	
	*/

    Container<char, double, std::string> c1;
    Container<char, double, int> c2;
    Container<char, char, int> c3;
    Container<float, float, int> c4;
}