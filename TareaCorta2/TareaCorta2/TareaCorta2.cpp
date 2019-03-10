#include "pch.h"
#include <iostream>
#include "ListaSimple.h"
#include "ListaSimpleB.h"

int main() {

	List<int> lm("Lista1");
	int x;

	lm.push_front(30);
	lm.push_front(20);
	lm.push_front(10);
	lm.push_back(40);
	lm.insertarR(5, 0);
	lm.insertarR(8, 1);
	lm.insertarR(15, 5);
	lm.insertarR(50, 99);
	lm.insertarR(999, 1);

	lm.remove(1, x);
	lm.pop(x);
	lm.pop_back(x);
	//cout <<"Prueba: "<< x;


	lm.print();
	std::cout << "\n";
	List<string> la("Personas");
	la.push_back("ana");
	la.push_back("juan");
	la.print();

	int z;
	ListaB<int> lb("Lista ejemplo");
	lb.push_front(10);
	lb.push_back(5);
	lb.push_front(9);
	lb.push_back(8);
	//lb.remove(1,z);
	//lb.insertar(90,2);
	lb.print();
	std::cout << "\n";
}