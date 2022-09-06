//Without templates

#include <iostream>
using namespace std;

class Bill {
public:
    Bill(int val) : val {val} {}
    friend ostream& operator << (ostream& os, Bill const& b)
    {
        return os << b.val;
    }

private:
    int val;    
};

void Scrie(int a);
void Scrie(const char* a);
void Scrie(Bill a);

int main()
{
    Scrie(10); // se va apela functia Scrie() cu parametrul de tip int
    Scrie("Name"); // se va apela functia Scrie() cu parametrul de tip const char*

    Bill b {100};
    Scrie(b); // se va apela functia Scrie() cu parametrul de tip Bill
}

void Scrie(int a)
{
    cout << a << '\n';
}

void Scrie(const char* a)
{
    cout << a << '\n';
}

void Scrie(Bill a)
{
    cout << a << '\n';
}