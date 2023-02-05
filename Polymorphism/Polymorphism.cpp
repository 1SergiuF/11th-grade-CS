/*
	Polimorfism, conditii:
	Cand o clasa contine cel putin o functie virtuala
	spunem ca este un Tip Polimorfic

	Cand un obiect contine o functie virtuala,
	spunem ca este un obiect polimorfic

	Cand o functie este declarata virtual,
	atunci spunem ca esteo functie virtuala
*/

#include <iostream>

class Being {
public:
    virtual void eats()
    {
        std::cout << "The being is eating\n";
    }

    virtual ~Being() {}
};

class Human : public Being {
public:
    virtual void eats() override
    {
        std::cout << "The human is eating\n";
    }
};

class Woman : public Human {
public:
    virtual void eats() override
    {
        std::cout << "The woman is eating\n";
    }
};

class Man : public Human {
public:
    virtual void eats() override
    {
        std::cout << "The man is eating\n";
    }
};

class Animal : public Being {
public:
    virtual void eats() override
    {
        std::cout << "The animal is eating\n";
    }
};

class Dog : public Animal {
public:
    void eats() override
    {
        std::cout << "The dog is eating\n";
    }
};

class Cat : public Animal {
public:
    void eats() override
    {
        std::cout << "The cat is eating\n";
    }
};

int main()
{
    Being *ptr = nullptr;
    char c;

    do {
        std::cout << "B - Being\n";
        std::cout << "H - Human\n";
        std::cout << "W - Woman\n";
        std::cout << "M - Man\n";
        std::cout << "A - Animal\n";
        std::cout << "D - Dog\n";
        std::cout << "C - Cat\n";
        std::cout << "X - Exit\n";
        std::cin >> c;

        switch(c)
        {
            case 'B':
            case 'b':
                ptr = new Being();
                break;

            case 'H':
            case 'h':
                ptr = new Human();
                break;

            case 'W':
            case 'w':
                ptr = new Woman();
                break;

            case 'M':
            case 'm':
                ptr = new Man();
                break;

            case 'A':
            case 'a':
                ptr = new Animal();
                break;

            case 'D':
            case 'd':
                ptr = new Dog();
                break;

            case 'C':
            case 'c':
                ptr = new Cat();
                break;

            default:
                std::cout << "Command not found\n";
        }

        if (ptr != nullptr)
        {
            ptr->eats();    // polimorfism
            delete ptr;
            ptr = nullptr;
        }

    } while (c != 'X' && c != 'x');
}