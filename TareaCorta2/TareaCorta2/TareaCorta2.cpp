#include "pch.h"
#include <iostream>
#include "ListaSimple.h"
#include "ListaSimpleB.h"

using namespace std;

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


	lm.print();
	std::cout << "\n";
	List<string> la("Personas");
	la.push_back("ana");
	la.push_back("juan");
	la.print();

	//int z;
	ListaB<int> lb("Lista ejemplo");
	int z;
	lb.push_front(1);
	lb.push_back(2);
	lb.push_back(3);
	lb.push_back(4);
	lb.push_back(5);
	lb.push_back(6);
	lb.push_back(7);
	lb.push_back(8);
	lb.push_back(9);
	lb.push_back(10);
	lb.push_back(11);
	lb.push_back(12);
	lb.push_back(13);
	lb.push_back(14);
	lb.push_back(15);
	lb.push_back(16);
	lb.push_back(17);
	lb.push_back(18);
	lb.push_back(19);
	lb.push_back(20);
	lb.push_front(99);
	lb.insertar(13, 5);
	lb.remove(10,z);
	lb.print();
	cout << z << "\n";

	//Prueba del get_back(), get_front(), get(), pop_back() y pop()

	int w = 666;
	lb.get_back(w); cout <<"get_back=" << w << "\n";
	lb.get_front(w); cout << "get_front=" << w << "\n";
	lb.get(14, w); cout << "get, con posición 14=" << w << "\n";
	lb.pop_back(w); cout << "pop_back=" << w << "\n";
	lb.print();
	lb.pop(w); cout << "pop=" << w << "\n";
	lb.print();


	//Prueba de los métodos get(), get_back(), get_front()
	List<int> lp("\nListaP");
	lp.push_front(0);
	lp.push_back(1);
	lp.push_back(2);
	lp.push_back(3);
	lp.print();

	int y = 666;

	lp.get(2, y);
	cout << y << "\n";

	lp.get_front(y);
	cout << y << "\n";

	lp.get_back(y);
	cout << y << "\n";

	lp.get_back(y);
	cout << y << "\n";

	cout << "Presione cualquier tecla para salir";
	cin.ignore();
}