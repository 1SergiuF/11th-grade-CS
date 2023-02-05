#include <iostream>

// clasa de baza
class A {

};

// B - clasa derivata
class B : public A {

};

int main()
{
	// O referinta la tipul clasei de baza
	// poate referi obiecte de tip derivat
    B ob;
    A& r = ob;
}