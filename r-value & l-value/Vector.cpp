/**
    Left Value Reference    &
    Right Value Reference   &&

    &  - poate fi legat NUMAI la l-values
    && - poate fi legat NUMAI la r-values


    Right Value Reference(&&) s-a introdus
    pentru a se putea face un transfer de resurse
    de la un r-value catre un left-value
*/

#include <iostream>

template <typename T>
class Vector {
public:
    Vector() : n {0}, ptr {nullptr}
    {}

    Vector(size_t n, T const& value = T()) :
        n {n}, ptr {new T[n]}   // Achizitionam resurse
    {
        for (int i = 0; i < n; ++i)
            ptr[i] = value;
    }

    ~Vector()
    {
        delete[] ptr;   // Renuntam la resurse
    }

    // Supraincarcam operatorul de indexare
    T operator[](int index) const
    {
        return ptr[index];
    }

    size_t size() const
    {
        return n;
    }

private:
    size_t n; // nr de elem din vector
    T* ptr;   // retine adresa sirului alocat dinamic
};

int main()
{
    Vector<int> v1;     // vector vid
    Vector<int> v2(10); // vector vid

    for (size_t i = 0; i < v2.size(); ++i)
        std::cout << v2[i] << ' ';
}