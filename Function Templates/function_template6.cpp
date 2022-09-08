// Function Template - Sablon de functie

#include <iostream>

class Bill {
public:
    Bill(int val) : val {val} {}
    friend std::ostream& operator << (std::ostream& os, Bill const& b)
    {
        return os << b.val;
    }

private:
    int val;    
};

template <class T1, class T2>
void Write(T1 a, T2 b)
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
}

int main()
{
    // Argumente template explicite

    Write<std::string, int>("Maria", 17);
    Write<int>(3, 2.3); // T1 = int (explicit), T2 = double (dedus)
}