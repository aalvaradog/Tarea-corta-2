#include "pch.h"
#include <iostream>
#include "ListaSimple.h"
#include "ListaSimpleB.h"
#include <string>

using namespace std;

int main() {

	List<int> lm("Lista1");
	lm.push_front(5);
	lm.push_back(10);
	lm.push_front(55);
	lm.print();
	lm.insertar(20, 10);
	lm.print();
	cout << lm.len();
	int x;
	lm.pop(x);
	
	string x;
	cin >> x ;
	return 0;
}