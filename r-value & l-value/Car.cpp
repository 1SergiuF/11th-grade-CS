/**
    Left Value Reference    &
    Right Value Reference   &&

    &  - poate fi legat NUMAI la l-values
    && - poate fi legat NUMAI la r-values


    Right Value Reference(&&) s-a introdus
    pentru a se putea face un transfer de resurse
    de la un r-value catre un left-value
*/

#include <iostream>

class Car {
public:
    Car() : speed {0}
    {}

    Car(int speed) : speed {speed}
    {}

    ~Car()
    {}

    int GetSpeed() const noexcept
    {
        return speed;
    }

private:
    int speed;
};

int main()
{
    Car c1 {200};
    Car c2 {250};

    c1 = c2;  // Default Copy Assignment Operator

    std::cout << c1.GetSpeed();
}