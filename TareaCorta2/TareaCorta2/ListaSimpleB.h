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
	if (primero == NULL) {
		primero = new Node(NULL);
		primero->elemento[0] = x;
	}
	else if (primero->lleno == true) {
		primero = new Node(primero);
		primero->elemento[0] = x;
	}
	else if (tam == 1) {
		primero->elemento[1] = primero->elemento[0];
		primero->elemento[0] = x;
	}else{
		T con2;
		T con=primero->elemento[0];
		int conte = 0;
		while (conte < tam) {
			con2= primero->elemento[conte + 1];
			primero->elemento[conte + 1] = con;
			con = con2;
			conte++;
		}
		primero->elemento[0] = x;
	}
	tam += 1;
	if (tam == N) {
		primero->lleno = true;
	}
}

template<class T, int N>
void ListaB<T, N>::push_back(T x) {
	if (primero == NULL) {
		primero = new Node(NULL);
		primero->elemento[N-1] = x;
	}
	else if (primero->lleno == true) {
		primero = new Node(primero);
		primero->elemento[N-1] = x;
	}
	else {
		cout << tam;
		primero->elemento[tam] = x;
	}
	tam += 1;
	if (tam == N) {
		primero->lleno = true;
	}
}

template <class T, int N>
void ListaB<T,N>::insertar(T x, int pos) {
	if (primero == NULL) {
		primero = new Node(NULL);
		primero->elemento[pos] = x;
	}
	else if (!primero->lleno) {
		if (pos > tam) {
			primero->elemento[pos] = x;
		}
		else {
			T contenedor=primero->elemento[pos];
			T contenedor2;
			for (int y = pos; y <= tam; y++) {
				contenedor2 = primero->elemento[y + 1];
				primero->elemento[y + 1] = contenedor;
				contenedor = contenedor2;
			}
		}
	}
	else {
		int cant = 10;
		primero = new Node(primero);
		while (pos > cant) {
			if (primero->siguiente == NULL) {
				primero = new Node(primero);
			}
			primero = primero->siguiente;
			cant+=10;
		}
		return insertar(x, pos);
	}
	
}
template<class T, int N>
bool ListaB<T, N>::remove(int pos, T &x) {
	int cant = 10;
	int y = pos;
	T *contenedor;
	while (cant <= pos) {
		primero = primero->siguiente;
		cant += 10;
		y -= 10;
	}
	contenedor =&(primero->elemento[y]);
	delete[] contenedor;
	//primero->elemento[y] = NULL;
	return true;
}

template<class T, int N>
void ListaB<T,N>::print() {
	cout <<"\n"<< nombreLista << " = [";
	if (primero) {
		link p = primero;
		while(p){
		int cont = 0;
		cout << p->elemento[cont];
		while (cont+1 < tam) {
			cout <<", "<< p->elemento[cont+1];
			cont++;
		}
		p = p->siguiente;
		}
	}
	cout << "]";
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


