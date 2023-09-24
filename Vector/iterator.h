#ifndef ITERATOR_H
#define ITERATOR_H

template<
	template<typename> typename Container,
	typename T
>
class Iterator {
private:
	Container<T>& container;
	int index;	// index (pozitia in container)

public:
	Iterator(Container<T>& container, int index = 0) : container {container}, index {index}
	{}

	// ca sa lucreze ca un smart-pointer
    // trebuie implementate operatiile *, ->, ++

	// operator de deferentiere
	T operator *() const
	{
		return container[index];
	}

	T& operator *()
	{
		return container[index];
	}

	// operator de indirectare
	T* operator -> () const
	{
		return container + index;
	}

	T*& operator -> ()
	{
		return container + index;
	}

	// prefix (infix) increment operator ++it
	Iterator& operator ++()
	{
		index++;
		return *this;
	}

	// suffix (postfix) increment operator it++
	Iterator operator ++(int)
	{
		Iterator temp{ *this };
		index++;
		return temp;	
	}

	// operatori relationali
	
	bool operator == (Iterator const& it) const noexcept
	{
		return index == it.index;
	}

	bool operator != (Iterator const& it) const noexcept
	{
		return !(*this == it);
	}
};

#endif // !ITERATOR_H
