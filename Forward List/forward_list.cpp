#include <iostream>
#include <fstream>
#include "iterator.h"

template<typename T>
class forward_list {
private:
    
    // tip membru
    struct Node {
        int key;    // info
        Node* next; // urm
    };

    Node* first;

public:

    // type-alias-uri
    using reference = T&;
    using iterator = Iterator<forward_list>;
    using pointer = T*;
    using node_pointer = Node*;

    forward_list() : first {nullptr} // c-tor
    {}

    // adauga un nod cu valoarea value la inceputul listei
    void push_front(T const& value) 
    {
        first = new Node {value, first};
    }

    // sterge primul nod din lista
    void pop_front()
    {
        Node* ptr = first;
        first = first->next;
        delete ptr;
    }

    bool empty() const noexcept
    {
        return first == nullptr;
    }

    iterator begin() noexcept
    {
        return iterator(*this, first);
    }

    iterator end() noexcept
    {
        return iterator(*this, nullptr);
    }

    reference key(node_pointer ptr)
    {
        return ptr->key;
    }

    node_pointer next(node_pointer ptr)
    {
        return ptr->next;
    }

    // Functii utilitare
    
    void read_list(std::istream& is)
    {
        T value;
        while (is >> value)
            push_front(value);
    }

    void write_list(std::ostream& os)
    {
        for (node_pointer p = first; p; p = p->next)
            os << p->key << ' ';
    }
};

int main()
{
    forward_list<int> L;

    std::ifstream fin("lista.in");
    L.read_list(fin);

    auto i = L.begin();
    *i = 10000;

    std::ofstream fout("lista.out");
    //    L.write_list(fout);

    for (auto v : L)
        fout << v << ' ';
}