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
};template <class T, int N>
ListaB<T,N>::ListaB(string nombre) {
	nombreLista = nombre;
	primero = NULL;
	tam = 0;
}template<class T, int N>int ListaB<T,N>::len() {	return tam;}template<class T, int N>void ListaB<T,N>::push_front(T x) {	if (primero == NULL) {		primero = new Node(false, NULL);		primero->elemento[0] = x;	}
	else if (primero->lleno == true) {		primero = new Node(false, primero);		primero->elemento[0] = x;	}else {		T con;		int conte=0;		while (conte < N) {			con = primero->elemento[conte];			primero->elemento[conte + 1] = con;		}		primero->elemento[0] = x;		primero->tam += 1;		if (tam == N) {			primero->lleno = true;		}	}}template<class T, int N>void ListaB<T, N>::push_back(T x) {	if (primero == NULL) {		primero = new Node(false, NULL);		primero->elemento[N-1] = x;	}
	else if (primero->lleno == true) {		primero = new Node(false, primero);		primero->elemento[N-1] = x;	}	else {		T con;		int conte = N-1;		while (conte !=0) {			con = primero->elemento[conte];			primero->elemento[conte -1] = con;		}		primero->elemento[N-1] = x;		primero->tam += 1;		if (tam == N) {			primero->lleno = true;		}	}}
template <class T, int N>
void ListaB<T,N>::insertar(T x, int pos) {
	
}

template<class T, int N>
void ListaB<T,N>::print() {
	cout << nombreLista << " = [";
	if (primero) {
		link p = primero;
		while(p){
		int cont = 0;
		while (cont < N) {
			cout <<", "<< p->elemento[cont];
			cont++;
		}
		p = p->siguiente;
		cout << p->elemento;
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


