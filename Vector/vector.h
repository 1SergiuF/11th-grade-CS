#ifndef VECTOR_H  // guard block
#define VECTOR_H

#include <string>
#include <initializer_list>
#include "iterator.h"

template<typename T>
class Vector {
private:
	size_t n;  // nr de elem din vector
	T* ptr;    // retine adresa sirului alocat dinamic

public:
	// Member Types
	using iterator = Iterator<Vector, T>;

	Vector() : n{ 0 }, ptr{ nullptr }
	{}

	Vector(size_t n, T const& value = T()) : n{ n }, ptr{ new T[n] } // Achizitionam resurse
	{
		for (size_t i = 0; i < n; ++i)
			ptr[i] = value;
	}

	Vector(std::initializer_list<T> list) : n{ list.size() }, ptr{ new T[n] }
	{
		int index = 0;
		for (auto it = list.begin(); it != list.end(); ++it)
			ptr[index++] = *it;
	}

	// Copy Constructor (deep copy)
	Vector(Vector const& v) : n{ v.size() }, ptr{ new T[n] }
	{
		for (size_t i = 0; i < n; ++i)
			ptr[i] = v.ptr[i];
	}

	// Move Copy Constructor
	Vector(Vector&& v) : n{ v.size() }, ptr{ v.ptr }
	{
		v.n = 0;
		v.ptr = nullptr;  // IMPORTANT!!!
	}

	// Copy Assignment Operator
	Vector& operator = (Vector const& v)
	{
		if (this == &v) return *this;
		delete[] ptr;  // eliberam resursele
		n = v.n;
		ptr = new T[n];  // achizitionam noi resurse

		for (size_t i = 0; i < n; ++i)
			ptr[i] = v.ptr[i];

		return *this;
	}

	// Move Assignment Operator (operator atribuire-mutare)
	Vector& operator = (Vector&& v)
	{
		if (this == &v) return *this;
		delete[] ptr;  // eliberam resursele

		n = v.n;
		ptr = v.ptr;
		v.ptr = nullptr;  // IMPORTANT!!!

		return *this;
	}

	~Vector()
	{
		delete[] ptr;  // Renuntam la resurse
	}

	// Supraincarcam operatorul de indexare
	T operator [](int index) const
	{
		return ptr[index];
	}

	T& operator [](int index)
	{
		return ptr[index];
	}

	size_t size() const
	{
		return n;
	}

	iterator begin() noexcept
	{
		return iterator(*this);
	}

	iterator end() noexcept
	{
		return iterator(*this, n);
	}

	bool empty() const noexcept
	{
		return size() == 0;
	}
};

#endif // !VECTOR_H

