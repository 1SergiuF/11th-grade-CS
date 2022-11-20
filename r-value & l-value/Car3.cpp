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

    // Copy Constructor
    Car(Car const& car) : speed {car.speed}
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
    
    // Move Copy Constructor
    Car(Car&& car) : speed {car.speed}
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

    int GetSpeed() const noexcept
    {
        return speed;
    }

private:
    int speed;
};

int main()
{
    Car c1 = {200};
    // c2, c3, c4 -> se construiesc prin copiere
    Car c2 = std::move(c1), c3 (std::move(c2)), c4 {std::move(c3)};
}