#include <iostream>

int main()
{
    int x = 1, y = 2, z = 3;

    /*
        Capturam prin VALOARE toate variabilele din
        domeniul care contine expr. lambda (Enclosing Scope)
    */

    auto Test = [=](int a)
    {
        std::cout << a << ' ';  // OK
        std::cout << x << ' ';  // OK - x capturat prin valoare
        std::cout << y << ' ';  // OK - y capturat prin valoare
        std::cout << z << ' ';  // OK - z capturat prin valoare

        //  x = 10;   // NO!
        //  y = 20;   // NO!
        //  z = 30;   // NO!

    };

    Test(100);
}