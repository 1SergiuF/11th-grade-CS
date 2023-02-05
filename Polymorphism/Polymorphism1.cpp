#include <iostream>

// clasa de baza
class A {

};

// B - clasa derivata
class B : public A {

};

int main()
{
	// Un pointer la clasa de baza poate
	// retine adrese ale obiectelor de tip derivat
    A* ptr = new B(); // OK!
}