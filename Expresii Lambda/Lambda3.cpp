#include <iostream>

int main()
{
    int x = 1, y = 2, z = 3;

    /*
        x, y - capturate prin valoare
        z    - capturat prin referinta
    */

   auto Test = [x, y, &z](int a)
   {
        std::cout << a << ' ';  // OK
        std::cout << x << ' ';  // OK - x capturat prin valoare
        std::cout << y << ' ';  // OK - y capturat prin valoare
        std::cout << z << ' ';  // OK - z capturat prin referinta

        //x = 10;   // NO!
        //y = 20;   // NO!
        z = 30;     // OK!
   };

   Test(100);

   std::cout << '\n' << z;
}