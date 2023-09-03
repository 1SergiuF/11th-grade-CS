#ifndef VECTOR_H  // guard block
#define VECTOR_H

#include <string>
#include <initializer_list>
#include "iterator.h"

template<typename T>
class Vector {
private:
	size_t cap; // capacitatea vctorului
	size_t n;  // nr de elem din vector
	T* ptr;    // retine adresa sirului alocat dinamic

public:
	// Member Types
	using iterator = Iterator<Vector, T>;

	Vector() : cap { 0 }, n{ 0 }, ptr{ nullptr }
	{}

	Vector(size_t n, T const& value = T()) : cap { n }, n{ n }, ptr{ new T[cap] } // Achizitionam resurse
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
	Vector(Vector const& v) : cap { v.cap }, n{ v.size() }, ptr{ new T[cap] }
	{
		for (size_t i = 0; i < n; ++i)
			ptr[i] = v.ptr[i];
	}

	// Move Copy Constructor
	Vector(Vector&& v) : cap { v.cap }, n{ v.n }, ptr{ v.ptr }
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

	size_t capacity()
	{
		return cap;
	}

	void push_back(T const& value)
	{
		if (size() + 1 > capacity())
			reserve(cap == 0 ? 2 : 2 * cap);

		ptr[n++] = value;
	}

	void pop_back()
	{
		n--;
		// optional
		if (2 * size() <= capacity())
			shrink_to_fit();
	}

	void shrink_to_fit()
	{
		if (size() == capacity()) return;

		T* new_ptr = new T[n];
		for (int i = 0; i < n; ++i)
			new_ptr[i] = ptr[i];

		delete[] ptr;
		ptr = new_ptr;
		cap = n;
	}

	void reserve(size_t new_cap)
	{
		if (new_cap <= capacity()) return;

		T* new_ptr = new T[new_cap];
		for (int i = 0; i < n; ++i)
			new_ptr[i] = ptr[i];

		delete[] ptr;
		cap = new_cap;
		ptr = new_ptr;
	}
};

#endif // !VECTOR_H

