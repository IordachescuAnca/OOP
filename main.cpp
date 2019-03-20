#include<iostream>
#include<fstream>
#include<string.h>
#include<algorithm>
using namespace std;

ifstream fin("stiva.txt");

template<class T>

class Nod
{

private:

	T caracter;
	Nod<T> *urm;

public:

	Nod() 
	{
		this->caracter=0;
		this->urm = NULL;
	}	

	Nod(T caracter_x) : caracter(caracter_x) 
	{
		this->urm = NULL;
	}
	
	Nod(const Nod &n)
	{
		caracter = n.caracter;
		urm = n.urm;
	}
	
	T get_caracter()
	{
		return caracter;
	}

	void setUrm(Nod *urm)
	{
		this->urm = urm;
	}

	Nod *get_urm()
	{
		return urm;
	}

	template<class U>friend class Stiva;

	friend istream &operator>>(istream &in, Nod &n)
	{
		in >> n.caracter;
		n.urm = NULL;
		return in;
	}
	friend ostream &operator<<(ostream &out, Nod &n)
	{
		out << n.get_caracter();
		return out;
	}

	bool operator <(Nod b) const
	{
		return (this->caracter < b.caracter);
	}
	bool operator >(Nod b) const
	{
		return (this->caracter > b.caracter);
	}
	bool operator ==(Nod b) const
	{
		return (this->caracter == b.caracter);
	}
	bool operator <=(Nod b) const
	{
		return ((*this) == b || (*this) < b);
	}
	bool operator !=(Nod b) const
	{
		return (this->caracter != b.caracter);
	}

	Nod &operator =(const Nod &a)
	{
		if (this == &a)
		{
			return *this;
		}
		this->caracter = a.caracter;
		this->urm = a.urm;

		return *this;
	}
	~Nod() {};
};

template<class T>
class Stiva
{
private:

	Nod<T> *inceput;
	int dimensiune;
	T varf;

public:

	Stiva()
	{
		inceput = NULL;
		dimensiune = 0;
		varf = 0;
	}

	void push(T caracter_x)
	{
		Nod<T> *new_nod = new Nod<T>(caracter_x);
		if (inceput == NULL)
		{
			new_nod->setUrm(NULL);
			inceput = new_nod;
		}
		else
		{
			new_nod->setUrm(inceput);
			inceput = new_nod;
		}
		varf = caracter_x;
		dimensiune++;
	}

	void pop()
	{
		if (inceput == NULL)
		{
			return;
		}
		if (inceput->get_urm() == NULL)
		{
			Nod<T> *aux = inceput;
			inceput = NULL;
			delete aux;
			dimensiune--;
			varf = 0;
			return;
		}
		Nod<T> *aux = inceput;
		inceput = inceput->get_urm();
		delete aux;
		varf = inceput->get_caracter();
		dimensiune--;
	}

	void inversare(char a[])
	{
		int n = strlen(a);

		for (int i = 0; i < n; i++)
		{
			push(a[i]);
		}

		for (int i = 0; i < n; i++)
		{
			a[i] = top();
			pop();
		}
	}

	T top()
	{
		return varf;
	}
	int size()
	{
		return dimensiune;
	}

	Stiva operator -(Stiva b)
	{
	 	if (dimensiune != b.dimensiune)
	 	{
	 		return (*this);
	 	}
	 	while (dimensiune != 0)
	 	{
	 		if (top() == b.top())
	 		{
	 			pop();
	 			b.pop();
	 		}
	 		else
	 		{
	 			break;
	 		}
	 	}
	 	return (*this);
	}

	friend istream &operator>>(istream &in, Stiva &s)
	{
		Nod<T> n;
		in >> n;
		char x = n.get_caracter();
		s.push(x);
		return in;
	}

	friend ostream &operator<<(ostream &out, Stiva &s)
	{
		Nod<T> aux(s.inceput->get_caracter());
		out << aux;
		s.pop();
		return out;
	}

	void afisare()
	{
		if (!dimensiune)
		{
			return;
		}
		while (dimensiune)
		{
			cout<<(*this)<<" ";
		}
	}

	friend bool operator <(const Stiva &a, const Stiva &b)
	{
		return (a.dimensiune < b.dimensiune);
	}
	friend bool operator >(const Stiva &a, const Stiva &b) 
	{
		return (a.dimensiune > b.dimensiune);
	}

	friend bool operator <=(const Stiva &a, const Stiva &b) 
	{
		return (a < b || a == b);
	}
	friend bool operator >=(const Stiva &a, const Stiva &b) 
	{
		return (a > b || a == b);
	}

	friend bool operator ==(const Stiva &a, const Stiva &b)
	{
		return (a.dimensiune == b.dimensiune);
	}
	friend bool operator !=(const Stiva &a, const Stiva &b) 
	{
		return (a.dimensiune != b.dimensiune);
	}

	Stiva(const Stiva &s)
	{
		this->inceput = NULL;
		dimensiune = 0;
		varf = 0;
		int cnt = s.dimensiune;

		while (cnt)
		{
			Nod<T> *aux = s.inceput;
			int i = 1;

			while (i < cnt)
			{
				i++;
				aux = aux->get_urm();
			}
			push(aux->get_caracter());
			cnt--;
		}
	}

	Stiva &operator =(const Stiva &s)
	{
		if (this == &s)
		{
			return *this;
		}

		while (dimensiune)
		{
			pop();
		}

		this->inceput = NULL;
		dimensiune = 0;
		varf = 0;

		int cnt = s.dimensiune;
		while (cnt)
		{
			Nod<T> *aux = s.inceput;
			int i = 1;

			while (i < cnt)
			{
				i++;
				aux = aux->get_urm();
			}
			push(aux->get_caracter());
			cnt--;
		}
		return (*this);
	}
	~Stiva() 
	{
		while (dimensiune)
		{
			pop();
		}
	};
};
int main()
{
	Stiva<char> *s;
	s = new Stiva<char>[10];
	int n;

	fin >> n;
	for (int i = 0; i < n; i++)
	{
		int nr;
		fin >> nr;

		for (int j = 0; j < nr; j++)
		{
			fin >> s[i];
		}
	}

	cout << "Stivele sortate arata astfel:\n";
	
	sort(s,s+n);
	
	for (int i = 0; i < n; i++)
	{
		s[i].afisare();
		cout << "\n";
	}
	cout << "\n";
	delete []s;

	Stiva<char> st;
	char sir[100];

	fin >> sir;
	cout << "Sirul de elemente inainte de inversare: " << sir << "\n";
	
	st.inversare(sir);
	
	cout << "Sirul de elemente dupa inversare: " << sir << "\n";


	Stiva<char> a, b;
	int x, y;

	fin >> x;
	for (int i = 0; i < x; i++)
	{
		fin >> a;
	}

	fin >> y;
	for (int i = 0; i < y; i++)
	{
		fin >> b;
	}
	Stiva<char> c = a - b;
	cout << "Diferenta dintre cele doua stive: ";
	c.afisare();
	cout << "\n";


	fin.close();
	return 0;
}
