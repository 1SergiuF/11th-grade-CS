#include <iostream>

class Employee {
public:
	Employee() : name {""}, job {""}, salary {0}
	{}

	Employee(std::string const& name, std::string const& job,
			int salary) :
	name {name}, job {job}, salary {salary}
	{}

	// Conversion operators
	operator std::string () const noexcept
	{
		return name;
	}

	operator int () const noexcept
	{
		return salary;
	}

private:
	std::string name;
	std::string job;
	int salary;
};

int main()
{
	Employee e1 {"Ioana", "front-end developer", 8000};
	Employee e2 {"Nicu", "front-end developer", 7000};

	std::string name1 = e1;
	std::string name2 = e2;
	int sal1 = e1;
	int sal2 = e2;

	std::cout << name1 << ' ' << name2 << '\n';
	std::cout << sal1 << ' ' << sal2;
}