// ThreeWayOperator
// Spaceship operator

#include <iostream>
#include <string>

class Employee {
public:
	Employee() : name {""}, job {""}, salary {0}
	{}

	Employee(
			std::string const& name,
			std::string const& job,
			int salary
		) :

	name {name},
	job {job},
	salary {salary}

	{}

	// Spaceship operator
	auto operator <=> (Employee const& e) const = default

private:
	std::string name;
	std::string job;
	int salary;
};

int main()
{
	Employee e1 {"Ioana", "front-end developer", 8000};
	Employee e2 {"Ion", "back-end developer", 7000};

	auto Write = [&]()
	{
		if (e1 < e2) std::cout << "e1 < e2\n";
		if (e1 <= e2) std::cout << "e1 <= e2\n";
		if (e1 > e2) std::cout << "e1 > e2\n";
		if (e1 >= e2) std::cout << "e1 >= e2\n";
		if (e1 != e2) std::cout << "e1 != e2\n";
		if (e1 == e2) std::cout << "e1 == e2\n";
	};

	Write();
}