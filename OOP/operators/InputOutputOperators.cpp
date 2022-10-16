#include <iostream>

class Employee {
public:
	Employee() : name {""}, job {""}, salary {0}
	{}

	template <class OutputStream>
	friend auto& operator << (OutputStream& os, Employee const& emp)
	{
		return os << emp.name << ' ' << emp.job << ' ' << emp.salary;
	}

	template <class InputStream>
	friend auto& operator >> (InputStream& is, Employee& emp)
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
	Employee emp;
	std::cin >> emp;
	std::cout << emp;
}