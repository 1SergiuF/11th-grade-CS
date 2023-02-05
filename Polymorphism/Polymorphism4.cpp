/*
	Polimorfism, conditii:
	- o ierarhie de clasa
	- cel putin o functie virtuala in clasa de baza
	- functia virtuala trebuie redefinita in clasele derivate
	   (Funciton overriding)

*/

#include <iostream>

// clasa de baza
class A {
public:
    virtual void Function() // functie virtuala
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
};

// B - clasa derivata
class B : public A {
public:
    void Function() override
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
};

int main()
{
    A* ptr = nullptr;

    ptr = new B();

	/* Legare Dinamica(Dynamic Binding)
	* 
	* Legare : asocierea unui apel de functie cu codul care va fi executat
	* Cand decizia se ia in timpul rularii, avem Dynamic Binding
	* (legarea se face in functie de tipul obiectului creat run-time)
	*/ 

    // Polimorfism
    ptr->Function();  // B::Function()

    delete ptr;  // ❌ OBJECT SLICING
}