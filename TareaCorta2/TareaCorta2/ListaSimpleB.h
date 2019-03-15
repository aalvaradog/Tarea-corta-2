#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
template <class T, int N = 10>
class ListaB {
	struct Node {
		bool lleno; // Indica si el nodo está lleno
		T elemento[N]; // Cada nodo almacena N elementos
		struct Node * siguiente; // Puntero al siguiente nodo
// Constructores
		Node() :lleno{ false }, siguiente{ 0 } {}
		Node(struct Node * sig) :lleno{ false },
			siguiente{ sig } {}
	};

	typedef struct Node * link;

	link primero; // Puntero al primer nodo
	int tam; // Cantidad de elementos totales en la lista
	string nombreLista; // Nombre de la lista

public:
	ListaB(string s);
	int len();
	void push_front(T x);
	void push_back(T x);
	void insertar(T x, int pos);
	bool remove(int pos, T& x);
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& element);
	bool get_front(T& element);
	bool get_back(T& element);
	~ListaB();
	void print();
};

template <class T, int N>
ListaB<T,N>::ListaB(string nombre) {
	nombreLista = nombre;
	primero = NULL;
	tam = 0;
}

template<class T, int N>
int ListaB<T,N>::len() {
	return tam;
}
template<class T, int N>
void ListaB<T,N>::push_front(T x) {
	link p = primero;
	if (primero == NULL) {
		primero = new Node(NULL);
		primero->elemento[0] = x;
	}
	else {
		T c2;
		T valor = x;
		int cont = 0;
		while (cont <= tam) {
			T c = p->elemento[0];
			for (int i = 0; i+1 < N; i++) {
				c2 = p->elemento[i + 1];
				p->elemento[i + 1] = c;
				c = c2;
			}
			p->elemento[0] = valor;
			valor = c;
			cont+=N;
			if (p->lleno==true && !p->siguiente) {
				p->siguiente = new Node(NULL);
			}
			p = p->siguiente;
		}
	}
	tam++;
	if (tam%N == 0) {
		p->lleno = true;
	}
}

template<class T, int N>
void ListaB<T, N>::push_back(T x) {
	link p = primero;
	if (primero == NULL) {
		primero = new Node(NULL);
		primero->elemento[0] = x;
	}
	while (p->siguiente) {
		p = p->siguiente;
	}
	if (p->lleno) {
		p->siguiente = new Node(NULL);
		p = p->siguiente;
	}
	p->elemento[tam%N] = x;
	tam++;
	if (tam%N == 0) {
		p->lleno = true;
	}
}

template <class T, int N>
void ListaB<T,N>::insertar(T x, int pos) {
	if (!primero) {
		primero = new Node(NULL);
	}
	link p = primero;
	int cont = N;
	while (cont <= pos) { //se posiciona en el nodo donde se ecnuentra pos
		if (!p->siguiente) {
			p->siguiente = new Node(NULL);
		}
		p = p->siguiente;
		cont += N;
	}
	T c = p->elemento[pos%N];
	T c2;
	for (int i = pos%N; i + 1 < N; i++) {
		c2 = p->elemento[i + 1];
		p->elemento[i + 1] = c;
		c = c2;
	}
	p->elemento[pos%N] = x;
	if (cont < tam) {
		if (!p->siguiente) {
			p->siguiente = new Node(NULL);
		}
		p = p->siguiente;
		T valor = p->elemento[0];
		while (cont < tam) {
			for (int i = 0; i < N; i++) {
				c2 = p->elemento[i];
				p->elemento[i] = c;
				c = c2;
			}
			valor = c;
			cont += N;
			if (p->lleno == true && !p->siguiente) {
				p->siguiente = new Node(NULL);
			}
			p = p->siguiente;
		}
	}
	tam++;
}

template<class T, int N>
bool ListaB<T, N>::remove(int pos, T &x) {
	if (pos > tam) {
		return false;
	}
	else {
		link p = primero;
		int cont = N;
		while (cont <= pos) {
			p = p->siguiente;
			cont += N;
		}
		x = p->elemento[pos%N];
		for (int i = pos % N; i + 1 < N; i++) {
			p->elemento[i] = p->elemento[i+1];
		}
		if (!p->siguiente) {
		}
		else {
			p->elemento[N - 1] = p->siguiente->elemento[0];
			p = p->siguiente;
			while (cont < tam) {
				for (int i = 0; i + 1 < N; i++) {
					p->elemento[i] = p->elemento[i+1];
				}
				cont += N;
				if (p->siguiente) {
					p = p->siguiente;
				}
			}
		}
		tam--;
		if (tam%N != 0) {
			p->lleno = false;
		}
	}return true;
}


template<class T, int N>
bool ListaB<T, N>::pop(T& x) {
	if (this->tam > 0) {
		x = this->primero->elemento[0];
		int n;
		this->remove(0, n);
		return true;
	}
	else {
		return false;
	}
}

template<class T, int N>
bool ListaB<T, N>::pop_back(T& x) {
	if (this->tam > 0) {
		int count = tam;
		link p = this->primero;
		while (p->siguiente) {
			p = p->siguiente;
			count -= 10;
		}
		for (int i = 0; i < count; i++) {
			x = p->elemento[i];
		}
		int n;
		this->remove(this->tam - 1, n);
		return true;

	}
	else
		return false;
}

template<class T, int N>
bool ListaB<T, N>::get(int pos, T& x) {
	if (this->tam > 0 && pos < this->tam) {
		link p = this->primero;
		while (pos >= N) {
			p = p->siguiente;
			pos -= N;
		}
		x = p->elemento[pos];
		return true;
	}
	else
		return false;
}


template<class T, int N>
bool ListaB<T, N>::get_front(T& x) {
	if (this->tam > 0) {
		x = this->primero->elemento[0];
		return true;
	}
	else {
		return false;
	}
}

template<class T, int N>
bool ListaB<T, N>::get_back(T& x) {
	if (this->tam > 0) {
		int count = tam;
		link p = this->primero;
		while (p->siguiente) {
			p = p->siguiente;
			count -= 10;
		}
		for (int i = 0; i < count; i++) {
			x = p->elemento[i];
		}
		return true;

	}
	else
		return false;
}

template<class T, int N>
void ListaB<T,N>::print() {
	
	if (primero) {
		link p = primero;
		cout << "\n" << nombreLista << " = [";
		if (tam) {
			cout << primero->elemento[0];
		}
		unsigned int i = 1;
		while (i < tam && p != NULL) {
			if (i%N == 0) {
				p = p->siguiente;
			}cout << ", " << p->elemento[i%N];
			i++;
		}
		cout << "]\n";
	}
}

template<class T,int N>
ListaB<T,N>::~ListaB() {
	link p;
	while (primero) {
		// Borrra todos los elementos en la
		// lista.
		p = primero->siguiente;
		delete primero;
		primero = p;
	}
}


