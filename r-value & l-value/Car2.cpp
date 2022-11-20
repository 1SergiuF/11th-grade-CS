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

    // Copy Assignmet Operator
    Car& operator = (Car const& car)
    {
        speed = car.speed;
        std::cout << __PRETTY_FUNCTION__ << '\n';
        return *this;
    }

    // Move Assignmet Operator
    Car& operator = (Car&& car)
    {
        speed = car.speed;
        std::cout << __PRETTY_FUNCTION__ << '\n';
        return *this;        
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
    Car c1 {200};
    Car c2 {250};

    // functia std::move(a) transforma un r-value in l-value

    c1 = c2;  // Default Copy Assignment Operator
    c1 = std::move(c2);  // Move Assignment Operator
    std::cout << c1.GetSpeed();
}