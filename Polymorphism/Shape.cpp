#include <iostream>
#include <utility>
#include <vector>
#include <tuple>

class Patrulater {
public:
	Patrulater(std::string const& name = "patrulater") : name {name}
	{}

	Patrulater(int l, int L) : l {l}, L {L}
	{}

	Patrulater(int l) : l {l}
	{}

	virtual void Deseneaza() = 0;
	virtual int Arie() { return l * L; };
	virtual void Push(Patrulater*) {};

	virtual ~Patrulater() {};

protected:
	std::string name;
	int l;
	int L;
};

class Patrat : public Patrulater {
public:
	Patrat(int l) : Patrulater(l)
	{}

	void Deseneaza() override
	{
		std::cout << "Deseneaza un patrat !\n";
	}

	int Arie() override
	{
		return l * l;
	}
};

class Dreptunghi : public Patrulater {
public:
	Dreptunghi(int l, int L) : Patrulater(l, L)
	{}

	void Deseneaza() override
	{
		std::cout << "Deseneaza un dreptunghi !\n";
	}

	int Arie() override
	{
		return L * l;
	}
};

class ListaPatrulatere : public Patrulater {
public:
	ListaPatrulatere() : cnt {0}
	{}

	void Deseneaza() override
	{
		for (auto i : item)
			i.second->Deseneaza();
	}

	void Push(Patrulater* p) override
	{
		++cnt;
		item.push_back(std::make_pair(cnt, p));
		list.push_back(std::make_tuple(cnt, name, p->Arie()));
	}

	int Size() const noexcept
	{
		return cnt;
	}

	void ShowTuple() const noexcept
	{
		for (auto l : list)
			std::cout << std::get<0>(l) << ". "
					  << std::get<1>(l) << ' '
					  << std::get<2>(l) << '\n';
	}

	~ListaPatrulatere()
	{
		for (auto i : item)
			delete i.second;
	}

private:
	std::vector<std::pair<int, Patrulater*>> item;
	std::vector<std::tuple<int, std::string, int>> list;
	int cnt;
};

int main()
{
	Patrulater* p1 = new Patrat(10);
	Patrulater* p2 = new Patrat(12);
	Patrulater* d1 = new Dreptunghi(4, 5);
	Patrulater* d2 = new Dreptunghi(7, 9);

	ListaPatrulatere *list = new ListaPatrulatere();
	list->Push(p1);
	list->Push(p2);
	list->Push(d1);
	list->Push(d1);

	list->Deseneaza();
	std::cout << p2->Arie() << '\n';
	std::cout << list->Size() << '\n';
	list->ShowTuple();
}