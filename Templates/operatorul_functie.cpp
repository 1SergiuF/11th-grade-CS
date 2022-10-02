#include <iostream>

class Employee {
public:
    Employee() {}
    Employee(std::string const& name,
             std::string const& job,
             int salary) :
        name {name},
        job {job},
        salary {salary}
    {}

    void operator() (int a, int b)
    {
        std::cout << a << ' ' << b;
    }

    double operator() (double a, double b)
    {
        return a + b;
    }

    template <class Os>
    friend auto& operator << (Os& os, Employee const& emp)
    {
        return os << emp.name << ' '
                  << emp.job << ' '
                  << emp.salary;
    }

    template <class Is>
    friend auto& operator >> (Is& is, Employee& emp)
    {
        return is >> emp.name >> emp.job >> emp.salary;
    }

private:
    std::string name;
    std::string job;
    int salary;
};

int main()
{
    /*
        Un obiect functie (function object) poate
        fi apelat in maniera unei functii
    */

    Employee emp;   // emp - Function Object (Functor)
    emp(100, 300);  // emp.operator() (100, 300)
    std::cout << '\n';

    std::cout << emp(10.23, 4.90);
}