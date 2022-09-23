#include <iostream>

int main()
{
    // Clauza de Captura (Capture Clause)

     auto Suma = [](int a, int b) -> char //tip de return
    {
        return a + b;
    };

    std::cout << Suma(30, 35); // Utilizarea expr. lambda
}