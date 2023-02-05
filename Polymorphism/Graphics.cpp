/*
    Polimorfism
    Composite - Design Pattern
*/

#include <iostream>
#include <string>
#include <vector>

/*
    Graphics = clasa ABSTRACTA
    O clasa este abstracta daca contine cel putin o functie pur virtuala
    NU se pot construi obiecte de sine statatoare de tipul unei clase abstracte

    Clasele care mostenesc direct o clasa abstracta sunt OBILIGATE
    sa implementeze TOATE functiile pur virtuale din clasa abstracta.

*/

class Graphics {
public:
    Graphics(std::string const& name = "") : name {name}
    {}

    // Pure Virtual Function
    virtual void draw() = 0;

    virtual void add(Graphics* g) {};

    ~Graphics() {};

protected:
    std::string name;
};

class Circle : public Graphics {
public:
    Circle(std::string const& name = "") : Graphics(name)
    {}

    // Overriding - Redefinire
    void draw() override
    {
        std::cout << "Draw a " << name << '\n';
    }
};

class Line : public Graphics {
public:
    Line(std::string const& name = "") : Graphics(name)
    {}

    // Overriding - Redefinire
    void draw() override
    {
        std::cout << "Draw a " << name << '\n';
    }
};

class Painting : public Graphics {
public:
    Painting(std::string const& name = "") : Graphics(name)
    {}

    // Overriding - Redefinire
    void draw() override
    {
        for (Graphics* c : components)
            c->draw();
    }

    void add(Graphics* g) override
    {
        components.push_back(g);
    }

    ~Painting()
    {
        for (auto c : components)
            delete c;
    }

private:
    std::vector<Graphics*> components;
};

int main()
{
    // Graphics g; -> NU - Graphics este clasa abstracta
    Graphics* C1 = new Circle("Circle 1");
    Graphics* C2 = new Circle("Circle 2");
    Graphics* L1 = new Line("Line 1");
    Graphics* L2 = new Line("Line 2");

    Graphics* paint = new Painting("The Painting");
    paint->add(C1);
    paint->add(C2);
    paint->add(L1);
    paint->add(L2);

    paint->draw();

    delete paint;
}