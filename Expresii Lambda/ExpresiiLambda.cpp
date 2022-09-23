#include <iostream>

int g = 10;
int main()
{
    int x = 1, y = 2, z = 3;

    auto Test = [](int a)
    {
        std::cout << a; // OK
        g = 10;         // OK

        //std::cout << x; // NO! - nu este capturat x
        //std::cout << y; // NO!
        //z = 10;         // NO!
    };

    Test(100);
}