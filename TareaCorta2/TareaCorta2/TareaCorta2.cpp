#include "pch.h"
#include <iostream>
#include "ListaSimple.h"
#include "ListaSimpleB.h"

using namespace std;

int main() {

	List<int> lm("Lista1");
	lm.push_front(0);
	lm.push_back(1);
	lm.push_back(2);
	lm.push_back(3);
	int x = 55;
	lm.get_front(x);
	cout << x;

	lm.get_back(x);
	cout << x;
	lm.push_back(456);
	lm.get_back(x);
	cout << x;
	
	cin.ignore();
}