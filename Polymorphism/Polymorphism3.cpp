#include <iostream>

// clasa de baza
class A {
public:
    void Function()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
};

// B - clasa derivata
class B : public A {
public:
    void Function()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
};

int main()
{
    A* ptr = nullptr;

    ptr = new B();

	/* Legare Statica(Static Binding)
	* 
	* Legare : asocierea unui apel de functie cu codul care va fi executat
	* Cand decizia se ia in timpul compilarii, avem Static Binding
	* (compilatorul se orienteaza dupa tipul pointerului)
	*/ 

    ptr->Function(); // A::Function()

    delete ptr; // ❌ OBJECT SLICING
}