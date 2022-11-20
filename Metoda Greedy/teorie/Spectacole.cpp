/*
    Tehnica (metoda) Greedy
    Se aplica in probleme de optimizare (se cauta minim sau maxim)
    Consta in alegerea la fiecare pas al algoritmului al
    optimului local.
    Exista probleme care pot fi rezolvate corect cu greedy.

    Problema spectacolelor
    Se organizeaza un festival cu n spectacole.
    Pentru fiecare spectacol se cunosc: ora din inceput si
    ora de terminare.
    Sa se determine numarul maxim de spectacole intregi care
    pot fi urmarite.

    Ideea: se ordoneaza spectacolele crescator dupa
    timpii de terminare.
*/

#include <iostream>
using namespace std;

const int N = 1001;

struct Spectacol {
	int ord;	// nr de ordine
	int ti, tf; // timpii de inceput / final
};

int n;
Spectacol s[N];

void CitesteSpect();
void SorteazaSpect();
void Greedy();

int main()
{
	CitesteSpect();
	Greedy();
	
	return 0;
}

void CitesteSpect()
{
	cin >> n;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i].ti >> s[i].tf;
		s[i].ord = i;
	}
}

void SorteazaSpect()
{
	Spectacol aux;
	bool sortat = false;
	
	while (!sortat)
	{
		sortat = true;
		
		for (int i = 1; i < n; ++i)
			if (s[i].tf > s[i + 1].tf)
			{
				aux = s[i];
				s[i] = s[i + 1];
				s[i + 1] = aux;
			}
	}
}

void Greedy()
{
	SorteazaSpect();
	
	cout << s[1].ord << ' ' << s[1].ti
		 << ' ' << s[1].tf << '\n';
	
	int last = s[1].tf;		// ora de iesire de la ultimul spectacol
		 
	for (int i = 2; i <= n; ++i)
		if (s[i].ti >= last)
		{
			cout << s[i].ord << ' ' << s[i].ti
			     << ' ' << s[i].tf << '\n';
			     
			last = s[i].tf;
		}
}
