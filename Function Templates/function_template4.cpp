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

template <typename T>
T const& min(T const& a, T const& b)
{
    std::cout << "My min() function...\n";
    if (a <= b) return a;
    return b;
}

int main()
{
    std::cout << min(10, 20);
}