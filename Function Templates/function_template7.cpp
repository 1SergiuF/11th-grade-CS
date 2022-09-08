// Template Specialization
#include <iostream>

// Primary Template
template <class T>
void Write(T a)
{
    std::cout << "Primary Template\n";
}

// Template Specialization
// Full Specialization (e tot un sablon de functie)
template <>
void Write(double a)
{
    std::cout << "Full Specialization\n";   
}

// Non-Template Function
void Write(int a)
{
    std::cout << "Non-Template Function\n";
}

/*
   Daca exista un sablon de functie, o specializare si
   o functie non-template cu acelasi nume, si care potrivesc apelului
   atunci prioritatea de elegere este:
   1. Non-template function
   2. Specialization
   3. Primary Template
*/

int main()
{
    Write(100); // Non-Template Function
    Write("Name"); // Primary Template
    Write(2.3); // Specializare
}