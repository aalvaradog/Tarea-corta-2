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
		T c=p->elemento[0];
		T c2;
		T valor = x;
		int cont = 0;
		while (cont < tam) {
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
	while (cont <= pos) {
		if (!p->siguiente) {
			p->siguiente = new Node(NULL);
		}
		p = p->siguiente;
		cont += N;
	}
	T c = p->elemento[pos];
	T c2;
	T valor = x;
	while (cont < tam) {
		for (int i = 0; i + 1 < N; i++) {
			c2 = p->elemento[i + 1];
			p->elemento[i + 1] = c;
			c = c2;
		}
		p->elemento[0] = valor;
		valor = c;
		cont += N;
		if (p->lleno == true && !p->siguiente) {
			p->siguiente = new Node(NULL);
		}
		p = p->siguiente;
	}
	tam++;

	/**
	if (primero == NULL) {
		primero = new Node(NULL);
	}
	int cant = pos;
	link p = primero;
	while (tam < cant) {
		cant -= N;
		if (!p->siguiente) {
			p->siguiente = new Node(NULL);
		}
		p = p->siguiente;
	}
	p->elemento[pos%N - 1] = x;*/
}
template<class T, int N>
bool ListaB<T, N>::remove(int pos, T &x) {
	int cant = 10;
	int y = pos;
	T contenedor;
	while (cant <= pos) {
		primero = primero->siguiente;
		cant += 10;
		y -= 10;
	}
	primero->elemento[y] = NULL;
	return true;
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


