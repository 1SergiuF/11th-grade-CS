#ifndef __ITERATOR__ // guard block
#define __ITERATOR__

#endif // __ITERATOR__

template <typename Container>
class Iterator {
public:
    using reference    = typename Container::reference;     // T&
    using pointer      = typename Container::pointer;       // T*
    using node_pointer = typename Container::node_pointer;  // Node*

    Iterator(Container& c, node_pointer ptr) :
        c {c}, ptr {ptr}
    {}

    // pentru ca sa fie o clasa de iteratori,
    // trebuie implementate operatiile": *it, ++it, it->, !=

    reference operator *()
    {
        return c.key(ptr);
    }

    node_pointer operator-> ()
    {
        return ptr;
    }

    Iterator& operator ++ ()
    {
        ptr = c.next(ptr);
        return *this;
    }

    bool operator != (Iterator const& it) const noexcept
    {
        return ptr != it.ptr;
    }

private:
    Container& c;
    node_pointer ptr;
};