/*
	Tehnica RAII (Resource Aquisition Is Initialization)
	Se refera la gestionarea resurselor in C++

	The Rule of Three:
	Daca suntem obligati sa definim una dintre urmatoarele functii:
	1. Construcor (+ Copy Constructor)
	2. Copy Assignment Operator
	3. Destructor

	atunci suntem obligati sa le definim pe TOATE TREI!!!

*/

#include <iostream>
#include <initializer_list>

template <class T>
class Vector {
public:
	Vector() : n {0}, ptr {nullptr}
	{}

	Vector(size_t n, T const& val = T()) :
		n{ n }, ptr{ new T[n] }		// Achizitionam resurse
	{
		for (size_t i = 0; i < n; ++i)
			ptr[i] = val;
	}

	Vector(std::initializer_list<T> list) :
		n{ list.size() }, ptr{ new T[n] }
	{
		int index = 0;
		for (auto it = list.begin(); it != list.end(); ++it)
			ptr[index++] = *it;
	}

	// Copy Constructor
	Vector(Vector const& v) : n{ v.size() }, ptr{ new T[n] }
	{
		for (size_t i = 0; i < n; ++i)
			ptr[i] = v.ptr[i];
	}

	// Copy Assignment Operator
	Vector& operator = (Vector const& v)
	{
		if (this == &v) return *this;
		delete[] ptr;
		n = v.n;
		ptr = new T[n];

		for (size_t i = 0; i < n; ++i)
			ptr[i] = v.ptr[i];

		return *this;
	}

	~Vector() { delete[] ptr; }		// Renuntam la resurse
	
	// Supraincarcam operatorul de indexare
	T operator[](int index) const { return ptr[index]; }
	T& operator[](int index) { return ptr[index]; }

	size_t size() const noexcept { return n; }

	static void PrintVector(Vector<T> const& v)
	{
		for (size_t i = 0; i < v.size(); ++i)
			std::cout << v.operator[](i) << ' ';
		std::cout << '\n';
	}

private:
	size_t n;	// nr de elem din vector
	T* ptr;     // retine adresa sirului alocat dinamic
};

int main()
{
	Vector<int> vec {1, 2, 3, 4, 10};
	Vector<int>::PrintVector(vec);

	Vector<int> vec_2{ 100, 200, 300 };
	vec = vec_2;  // Copy Assignment Operator

	Vector<int>::PrintVector(vec);
}