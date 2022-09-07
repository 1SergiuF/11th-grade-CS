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
    // Are loc DEDUCEREA argumentelor template (const char*, int, double, char)
    // pe baza argumneleor de apelare

    Write("Name", 13);
    Write(12.5, 'B');
}