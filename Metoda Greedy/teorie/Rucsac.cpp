/*
    Problema Rucsacului - varianta continua/fractionara
    Se da rucsac de capacitate G Kg si n obiecte
    de greutati g[1]...g[i] si valori v[1]...v[i].

    Sa se determine valoarea maxima o obiectelor care pot fi puse
    in rucsac, astfel incat greutatea acestora sa nu depaseasca G;

    Observatie importanta: obiectele pot fi fractionate (taiate)

    Ideea:
    Se ordoneaza obiectele descrescator dupa raportul valoare / greutate
    Se aleg obiecte din sir pana can unul nu mai incape.
    Acesta se fractioneaza.

*/

#include <iostream>
using namespace std;

struct Obiect {
	int ord;	 // nr de ordine
	int gr, val; // greutate, valoare
	
	friend ostream& operator << (ostream& os, Obiect const& ob)
	{
		return os << ob.ord << ' ' << ob.gr << ' ' << ob.val
				  << '\n';
	}
};

const int N = 1001;

int n, G;
Obiect s[N];
double val_max;  // val maxima a obiectelor care pot fi puse in rucsac

void CitesteObiecte();
void SorteazaObiecte();
void Greedy();

int main()
{
	CitesteObiecte();
	Greedy();
	
	return 0;
}

void CitesteObiecte()
{
	cin >> n >> G;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i].gr >> s[i].val;
		s[i].ord = i;
	}
}

void SorteazaObiecte()
{
	Obiect aux;
	
	for (int i = 1; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (s[i].val * s[j].gr < s[j].val * s[i].gr)
			{
				aux = s[i];
				s[i] = s[j];
				s[j] = aux;
			}
}

void Greedy()
{
	SorteazaObiecte();
	
	int gr = 0;  // greutatea curenta a rucsacului
	
	for (int i = 1; i <= n; ++i)
		if (gr + s[i].gr <= G)
		{
			cout << s[i];
			val_max += s[i].val;
			gr += s[i].gr;
		}
		
		/*
		 * daca obiectul i nu mai incape in rucsac
		 * acesta se fractioneaza
		 */
		 
		else
		{
			double val = s[i].val * (G - gr) / s[i].gr;
			cout << s[i].ord << ' ' << G - gr << ' ' << val << '\n';
			val_max += val;
		}
		
	cout << val_max;
}
